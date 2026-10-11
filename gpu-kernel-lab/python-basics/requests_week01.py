def deduplicate_requests(requests):
    seen=set()
    new_requests=[]
    for item in requests:
        id=item["request_id"]
        if id not in seen:
            seen.add(id)
            new_requests.append(item)
    return new_requests
