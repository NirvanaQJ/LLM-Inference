requests = [
    {"request_id": "A", "latency_ms": 10},
    {"request_id": "B", "latency_ms": 20},
    {"request_id": "A", "latency_ms": 99},
]


def deduplicate_requests(requests):
    seen = set()
    new_requests = []
    for item in requests:
        id = item["request_id"]
        if id not in seen:
            seen.add(id)
            new_requests.append(item)
    return new_requests


print(deduplicate_requests(requests))

print("empty:", deduplicate_requests([]))

all_same = [
    {"request_id": "A", "latency_ms": 10},
    {"request_id": "A", "latency_ms": 99},
    {"request_id": "A", "latency_ms": 7},
]
print("all_same:", deduplicate_requests(all_same))
