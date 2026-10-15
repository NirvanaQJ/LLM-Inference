#pragma once

#include <string>
#include <vector>

struct Request {
    std::string request_id;
    double latency_ms;
};

double total_latency(const std::vector<Request>& requests);

bool parse_request(const std::string& line, Request& out);