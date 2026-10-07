import csv
import json
import sys
from pathlib import Path

input_path = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(
    "gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl"
)
try:
    lines = input_path.read_text(encoding="utf-8").splitlines()
except FileNotFoundError:
    raise SystemExit(f"文件不存在：{input_path}")

records = []
for line_no, line in enumerate(lines, start=1):
    try:
        record = json.loads(line)
    except json.JSONDecodeError as error:
        raise SystemExit(
            f"{input_path} 第 {line_no} 行：JSON 格式错误：{error.msg}"
        )
    valid_record = (
        isinstance(record, dict)
        and isinstance(record.get("request_id"), str)
        and bool(record["request_id"])
        and type(record.get("latency_ms")) is int
        and record["latency_ms"] >= 0
    )
    if not valid_record:
        raise SystemExit(f"{input_path} 第 {line_no} 行：字段不合法")
    records.append(record)

output_path = Path("gpu-kernel-lab/results/raw/sample.csv")
with output_path.open("w", encoding="utf-8", newline="") as output_file:
    writer = csv.writer(output_file)
    writer.writerow(["request_id", "latency_ms"])
    for record in records:
        writer.writerow([record["request_id"], record["latency_ms"]])

print(f"已写入 {len(records)} 条记录：{output_path}")
