requests = [
    {"request_id": "A", "latency_ms": 10},
    {"request_id": "B", "latency_ms": 20},
    {"request_id": "A", "latency_ms": 99},
    {"request_id": "C", "latency_ms": 5},
    {"request_id": "B", "latency_ms": 30},
]


def keep_last_requests(requests):
    seen = set()
    kept = []
    for item in reversed(requests):
        request_id = item["request_id"]
        if request_id not in seen:
            # 把 ID 加入 seen，并把完整的 item 加入 kept
            seen.add(request_id)
            kept.append(item)
    kept.reverse()
    return kept


print(keep_last_requests(requests))


print("empty:", keep_last_requests([]))

all_same = [
    {"request_id": "A", "latency_ms": 10},
    {"request_id": "A", "latency_ms": 99},
    {"request_id": "A", "latency_ms": 7},
]
print("all_same:", keep_last_requests(all_same))
