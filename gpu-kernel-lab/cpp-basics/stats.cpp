#include <iostream>
#include "request.hpp"
#include <cmath>



double total_latency(const std::vector<Request>& requests) {
    double total = 0.0;

    for (const Request& request : requests) {
        total += request.latency_ms;
    }

    return total;
}

int main() {
    std::vector<Request> requests;
    std::string line;

    while (std::getline(std::cin, line)) {
        Request request{};

        if (!parse_request(line, request)) {
            std::cerr << "无效请求记录\n";
            return 1;
        }

        requests.push_back(request);
    }

    if (!std::cin.eof()) {
        std::cerr << "读取输入失败\n";
        return 1;
    }

    double total = total_latency(requests);

    if (!std::isfinite(total)) {
        std::cerr << "总延迟超出可表示范围\n";
        return 1;
    }

    std::cout << "count=" << requests.size()
              << ", total_ms=" << total
              << ", avg_ms=";

    if (requests.empty()) {
        std::cout << "N/A\n";
    } else {
        std::cout << total / requests.size() << '\n';
    }

    return 0;
}