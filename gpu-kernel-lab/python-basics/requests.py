requests = [
    {"request_id": "A", "latency_ms": 10},
    {"request_id": "B", "latency_ms": 20},
    {"request_id": "A", "latency_ms": 99},
]



def deduplicate_requests(requests):
    seen = set()
    new_requests = []
    for request in requests:
        id = request["request_id"]
        if id in seen:
            continue
        else:
            seen.add(id)
        new_requests.append(request)
    return new_requests

print(deduplicate_requests(requests))

def mean_latency(requests):
    request = deduplicate_requests(requests)
    if len(request) == 0:
        return None
    total =0
    for item in request:
        total += item["latency_ms"]
    return total / len(request)

print(mean_latency(requests))