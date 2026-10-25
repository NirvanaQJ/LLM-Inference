#include <iostream>
#include <vector>
#include <string>

struct Request {
    std::string id;
    std::string model;
    double latency_ms;
};

void print_first(const std::vector<Request>& requests) {
    std::cout << requests.size() << "\n";
    if (requests.empty()) {
        std::cout << "EMPTY\n";
        return;
    }
    std::cout << requests[0].id << " "
              << requests[0].model << " "
              << requests[0].latency_ms << "\n";
}

int main() {
    std::vector<Request> request_container;
    request_container.reserve(2);
    request_container.push_back({"r1", "model-A", 30.0});
    request_container.push_back({"r2", "model-B", 10.0});

    const auto& req = request_container;
    print_first(request_container);
    std::vector<Request> copied = request_container;
    copied[0].id = "r9";
    std::cout << req[0].id << "\n"
              << copied[0].id << "\n";
    std::vector<Request> empty = {};
    print_first(empty);
}
