"""核对学习者在运行前确认的三组去重预期。"""

from pathlib import Path
import runpy


source_path = Path(__file__).resolve().parents[1] / "python-basics" / "requests_week01.py"
deduplicate_requests = runpy.run_path(str(source_path))["deduplicate_requests"]

# expected 独立写自 2026-10-11 学习者给出的预期，不从 actual 生成。
cases = [
    (
        "normal",
        [("A", 10), ("B", 20), ("A", 99), ("C", 5), ("B", 30)],
        [("A", 10), ("B", 20), ("C", 5)],
    ),
    ("empty", [], []),
    ("all_same", [("A", 10), ("A", 99), ("A", 7)], [("A", 10)]),
]

for name, input_pairs, expected_pairs in cases:
    requests = [
        {"request_id": request_id, "latency_ms": latency_ms}
        for request_id, latency_ms in input_pairs
    ]
    expected = [
        {"request_id": request_id, "latency_ms": latency_ms}
        for request_id, latency_ms in expected_pairs
    ]
    actual = deduplicate_requests(requests)
    if actual != expected:
        raise AssertionError(f"{name}: expected={expected!r}, actual={actual!r}")
    print(f"{name}: PASS {actual}")

print("3 cases passed")
