#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "用法：stats_cli CSV路径\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
    std::cerr << "无法打开文件\n";
    return 1;
}

std::string line;

    if (!std::getline(input, line)) {
        return 1;
    }
    if (line != "latency_ms") {
    std::cerr << "表头必须为 latency_ms\n";
    return 1;
}
    
int count = 0;
double total_ms = 0.0;

while (std::getline(input, line)) {
    std::istringstream row(line);
    double latency_ms = 0.0;
    char extra;

    if (!(row >> latency_ms) || (row >> extra) ||
        !std::isfinite(latency_ms) || latency_ms < 0 ||
        !std::isfinite(total_ms + latency_ms)) {
        std::cerr << "无效延迟数据\n";
        return 1;
    }

    count += 1;
    total_ms += latency_ms;
}
std::cout << "header=latency_ms\n";
std::cout << std::setprecision(15);
std::cout << "count=" << count << '\n';
std::cout << "total_ms=" << total_ms << '\n';
if (count == 0) {
    std::cout << "avg_ms=N/A\n";
} else {
    double avg_ms = total_ms / count;
    std::cout << "avg_ms=" << avg_ms << '\n';
}
    return 0;
}