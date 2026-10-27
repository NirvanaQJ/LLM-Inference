"""Controlled acceptance checks; no edits to the learner's implementation."""
import argparse
import errno
import hashlib
import json
from pathlib import Path
import platform
import subprocess
import tempfile

parser = argparse.ArgumentParser()
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
if args.output.exists():
    raise SystemExit(f'结果文件已存在，请另选 --output：{args.output}')

tests = Path(__file__).resolve().parent
source = tests.parent / 'cpp-basics/fd_copy.cpp'
payload = b'ABCDEF'  # Independent fixture, not generated from actual output.
definitions = [
    ('short_read', 0, payload, 2),
    ('short_write', 0, payload, 2),
    ('eintr', 0, payload, 2),
    ('write_zero', 1, b'', 2),
    ('write_error', 1, b'', 2),
    ('read_error', 1, b'', 2),
    ('close_source_error', 1, payload, 2),
    ('close_destination_error', 1, payload, 2),
    ('existing_destination', 1, b'KEEP', 1),
    ('missing_source', 1, None, 0),
    ('missing_parent', 1, None, 1),
    ('usage', 2, None, 0),
]
report = {
    'evidence_type': 'controlled syscall wrapper tests; injected errors are simulated',
    'source_snapshot': source.read_text(),
    'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
    'working_directory': str(Path.cwd()),
    'system': platform.platform(),
    'compiler': subprocess.run(['g++', '--version'], capture_output=True, text=True, check=True).stdout.splitlines()[0],
    'cases': [],
}

with tempfile.TemporaryDirectory(prefix='fd-acceptance-') as temporary:
    work = Path(temporary)
    driver = work / 'fd_fault_driver'
    compile_command = ['g++', '-std=c++17', '-Wall', '-Wextra', str(tests / 'fd_fault_driver.cpp'),
                       '-Wl,--wrap=read', '-Wl,--wrap=write', '-Wl,--wrap=close', '-o', str(driver)]
    build = subprocess.run(compile_command, capture_output=True, text=True)
    report['compile'] = {'command': compile_command, 'exit': build.returncode, 'stderr': build.stderr}
    if build.returncode:
        print(build.stderr)
    else:
        for name, expected_exit, expected_bytes, expected_closes in definitions:
            case_dir = work / name
            case_dir.mkdir()
            source_path, destination = case_dir / 'input.bin', case_dir / 'output.bin'
            source_path.write_bytes(payload)
            if name == 'missing_source':
                source_path = case_dir / 'absent.bin'
            if name == 'missing_parent':
                destination = case_dir / 'absent-parent/output.bin'
            if name == 'existing_destination':
                destination.write_bytes(b'KEEP')
            expected = {'program_exit': expected_exit, 'output_hex': None if expected_bytes is None else expected_bytes.hex(),
                        'output_exists': expected_bytes is not None, 'close_calls': expected_closes}
            item = {'name': name, 'expected': expected}
            command = [str(driver), name, str(source_path), str(destination)]
            item['command'] = command
            try:
                run = subprocess.run(command, capture_output=True, text=True, timeout=3)
                item.update(driver_exit=run.returncode, stdout=run.stdout, stderr=run.stderr)
                actual = json.loads(run.stdout)
                output_bytes = destination.read_bytes() if destination.exists() else None
                actual['output_hex'] = None if output_bytes is None else output_bytes.hex()
                actual['output_exists'] = destination.exists()
                conditions = [run.returncode == 0, actual['program_exit'] == expected_exit,
                              output_bytes == expected_bytes, actual['close_calls'] == expected_closes,
                              all(e['real_closed'] for e in actual['events'] if e['operation'] == 'close')]
                events = actual['events']
                if name in ('short_read', 'short_write'):
                    op = 'read' if name == 'short_read' else 'write'
                    conditions.append(any(e['operation'] == op and e['controlled'] and 0 < e['returned'] < e['requested'] for e in events))
                if name == 'short_read':
                    conditions.append(actual['read_calls'] == 4)
                if name == 'short_write':
                    conditions.append(actual['write_calls'] == 6)
                if name == 'eintr':
                    conditions.append(all(any(e['operation'] == op and e['returned'] == -1 and e['errno'] == errno.EINTR for e in events) for op in ('read', 'write')))
                if name in ('write_zero', 'write_error', 'read_error', 'close_source_error', 'close_destination_error'):
                    conditions.append(any(e['controlled'] for e in events))
                    conditions.append(bool(run.stderr.strip()))
                if name in ('existing_destination', 'missing_source', 'missing_parent', 'usage'):
                    conditions.append(bool(run.stderr.strip()))
                item['actual'] = actual
                item['passed'] = all(conditions)
            except (subprocess.TimeoutExpired, json.JSONDecodeError) as error:
                item.update(passed=False, error=str(error))
            report['cases'].append(item)
            print(f"{name}: {'PASS' if item['passed'] else 'FAIL'}")

report['passed'] = sum(case['passed'] for case in report['cases'])
report['total'] = len(definitions)
report['all_passed'] = report['compile']['exit'] == 0 and report['passed'] == report['total']
args.output.parent.mkdir(parents=True, exist_ok=True)
args.output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
print(f"result: {report['passed']}/{report['total']}")
print(f'report: {args.output}')
raise SystemExit(0 if report['all_passed'] else 1)
