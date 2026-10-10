import argparse
import csv
import math
import random
from pathlib import Path

parser = argparse.ArgumentParser(description="生成并分析模拟延迟")
parser.add_argument("--count", type=int, default=100, help="正整数样本数")
args = parser.parse_args()
if args.count <= 0:
    parser.error("--count 必须是正整数")

name = "latency" if args.count == 100 else f"latency-count-{args.count}"

rng = random.Random(20261010)
output = Path(f"gpu-kernel-lab/results/raw/{name}.csv")
output.parent.mkdir(parents=True, exist_ok=True)

with output.open("w", newline="", encoding="utf-8") as file:
    writer = csv.writer(file, lineterminator="\n")
    writer.writerow(["latency_ms"])

    for _ in range(args.count):
        latency_ms = round(rng.uniform(5, 50), 3)
        writer.writerow([latency_ms])

print(f"已生成 {args.count} 条模拟延迟：{output}")

with output.open("r", newline="", encoding="utf-8") as file:
    reader = csv.DictReader(file)
    values = [float(row["latency_ms"]) for row in reader]

count = len(values)
mean = sum(values) / count
ordered = sorted(values)
middle = count // 2

if count % 2 == 0:
    median = (ordered[middle - 1] + ordered[middle]) / 2
else:
    median = ordered[middle]

print(f"样本数={count}, 均值={mean:.3f} ms, 中位数={median:.3f} ms")

p95_rank = math.ceil(0.95 * count)
p95 = ordered[p95_rank - 1]
print(f"p95：排序后第 {p95_rank} 个值 = {p95:.3f} ms")

counts = [0] * 9

for value in values:
    group = min(int((value - 5) // 5), 8)
    counts[group] += 1

for group, frequency in enumerate(counts):
    left = 5 + group * 5
    right = left + 5
    print(f"{left}–{right} ms: {frequency}")

print(f"分组总数={sum(counts)}")

figure = Path(f"gpu-kernel-lab/results/figures/{name}.svg")
figure.parent.mkdir(parents=True, exist_ok=True)

svg = [
    '<svg xmlns="http://www.w3.org/2000/svg" width="720" height="340" viewBox="0 0 720 340">',
    '<rect width="720" height="340" fill="white"/>',
    '<text x="360" y="30" text-anchor="middle" font-size="20">模拟延迟分布（非 GPU 实测）</text>',
    '<line x1="55" y1="255" x2="690" y2="255" stroke="black"/>',
    '<text x="20" y="60" font-size="14">样本数</text>',
    '<text x="360" y="320" text-anchor="middle" font-size="14">延迟区间 (ms)</text>',
]

for group, frequency in enumerate(counts):
    left = 5 + group * 5
    right = left + 5
    x = 65 + group * 69
    height = frequency * 10
    y = 255 - height

    svg.append(f'<rect x="{x}" y="{y}" width="45" height="{height}" fill="#4472c4"/>')
    svg.append(f'<text x="{x + 22}" y="{y - 5}" text-anchor="middle" font-size="12">{frequency}</text>')
    svg.append(f'<text x="{x + 22}" y="276" text-anchor="middle" font-size="11">{left}–{right}</text>')

svg.append("</svg>")
figure.write_text("\n".join(svg), encoding="utf-8")
print(f"已生成分布图：{figure}")
