from pathlib import Path
import sys
import math
import subprocess

if len(sys.argv) != 2:
    print("用法：compare.py CSV路径", file=sys.stderr)
    raise SystemExit(1)
count = 0
total_ms = 0.0

try:
    with Path(sys.argv[1]).open(
        encoding="utf-8", newline="\n"
    ) as source:
        header = source.readline().rstrip("\n")
        if header != "latency_ms":
            raise ValueError("表头必须为 latency_ms")

        for line in source:
            if not line.isascii() or "_" in line:
                raise ValueError("无效延迟数据")

            latency_ms = float(line)
            if (
                not math.isfinite(latency_ms)
                or latency_ms < 0
                or not math.isfinite(total_ms + latency_ms)
            ):
                raise ValueError("无效延迟数据")

            count += 1
            total_ms += latency_ms

except (OSError, ValueError) as error:
    print(f"输入错误：{error}", file=sys.stderr)
    raise SystemExit(1)
try:
    cpp_program = (
        Path(__file__).resolve().parents[1]
        / "cpp-basics"
        / "stats_cli"
    )
    result = subprocess.run(
        [str(cpp_program), sys.argv[1]],
        capture_output=True,
        text=True,
    )

    if result.returncode != 0:
        raise ValueError(f"C++运行失败：{result.stderr.strip()}")

    cpp = {}
    for output_line in result.stdout.splitlines():
        key, value = output_line.split("=", 1)
        if key in cpp:
            raise ValueError("C++输出字段重复")
        cpp[key] = value
    expected_keys = {"header", "count", "total_ms", "avg_ms"}
    if set(cpp) != expected_keys or cpp["header"] != "latency_ms":
        raise ValueError("C++输出格式不正确")

    cpp_count = int(cpp["count"])
    cpp_total_ms = float(cpp["total_ms"])

    if cpp_count != count:
        raise ValueError("count 不一致")

    if cpp_total_ms < 0 or not math.isclose(
        total_ms, cpp_total_ms, rel_tol=1e-12, abs_tol=1e-9
    ):
        raise ValueError("total_ms 不一致")

    if count == 0:
        if cpp["avg_ms"] != "N/A":
            raise ValueError("空数据均值必须为 N/A")
    else:
        cpp_avg_ms = float(cpp["avg_ms"])
        if cpp_avg_ms < 0 or not math.isclose(
            total_ms / count,
            cpp_avg_ms,
            rel_tol=1e-12,
            abs_tol=1e-9,
        ):
            raise ValueError("avg_ms 不一致")

except (OSError, ValueError) as error:
    print(f"对照错误：{error}", file=sys.stderr)
    raise SystemExit(1)
if count == 0:
    avg_ms = "N/A"
else:
    avg_ms = f"{total_ms / count:.15g}"

print(f"header={header}")
print(f"count={count}")
print(f"total_ms={total_ms:.15g}")
print(f"avg_ms={avg_ms}")
print("compare=PASS")
