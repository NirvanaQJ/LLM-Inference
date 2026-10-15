#include "request.hpp"
#include <sstream>
#include <cmath>

bool parse_request(const std::string& line, Request& out) {
    std::istringstream input(line);
    Request parsed{};

    if (!(input >> parsed.request_id >> parsed.latency_ms)) {
        return false;
    }

    char extra;
    if (input >> extra) {
        return false;
    }

    if (!std::isfinite(parsed.latency_ms) || parsed.latency_ms < 0) {
        return false;
    }

    out = parsed;
    return true;
}