import argparse
import json
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("--input", required=True)
args = parser.parse_args()
count = 0
total_ms = 0

with Path(args.input).open(encoding="utf-8") as source:
    for line in source:
        record = json.loads(line)
        count += 1
        total_ms += record["latency_ms"]

if count == 0:
    avg_ms = "N/A"
else:
    avg_ms = total_ms / count
print(f"count={count}, total_ms={total_ms}, avg_ms={avg_ms}")
