#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Request {
    std::string id;
    std::string model;
    double latency_ms;
};

void sort_and_print(const std::string& label,
                    std::vector<Request> requests) {
    std::cout << "[" << label << "] size="
              << requests.size() << "\n";

    std::sort(requests.begin(), requests.end(),
        [](const Request& a, const Request& b) {
            return a.latency_ms < b.latency_ms;
        });

    for (const Request& r : requests) {
        std::cout << r.id << " "
                  << r.model << " "
                  << r.latency_ms << "\n";
    }
}

void group_and_print(const std::string& label,
                     const std::vector<Request>& requests) {
    std::unordered_map<std::string, std::vector<Request>> groups;

    for (const Request& r : requests) {
        groups[r.model].push_back(r);
    }

    std::cout << "[" << label << "] requests="
              << requests.size()
              << " groups=" << groups.size() << "\n";

    for (const auto& entry : groups) {
        std::cout << entry.first
                  << " count=" << entry.second.size() << "\n";

        for (const Request& r : entry.second) {
            std::cout << "  " << r.id << " "
                      << r.model << " "
                      << r.latency_ms << "\n";
        }
    }
}
int main() {
    sort_and_print("ordinary", {
        {"r1", "model-A", 30.0},
        {"r2", "model-B", 10.0},
        {"r3", "model-A", 20.0}
    });

    sort_and_print("empty", {});

    sort_and_print("single", {
        {"r0", "model-A", 7.0}
    });

    sort_and_print("ties", {
        {"r4", "model-A", 10.0},
        {"r5", "model-B", 10.0},
        {"r6", "model-A", 5.0}
    });
    group_and_print("mixed", {
        {"r1", "model-A", 30.0},
        {"r2", "model-B", 10.0},
        {"r3", "model-A", 20.0}
    });

    group_and_print("empty", {});

    group_and_print("same_model", {
        {"r7", "model-A", 8.0},
        {"r8", "model-A", 3.0}
    });
    group_and_print("group_order_limit", {
        {"q1", "model-A", 40.0},
        {"q2", "model-A", 5.0}
    });
}
