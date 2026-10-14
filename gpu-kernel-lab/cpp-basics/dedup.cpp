#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cerr << "无法读取一行输入\n";
        return 1;
    }

    std::istringstream input(line);
    std::string token;
    std::vector<long long> nums;

    while (input >> token) {
        std::istringstream number_input(token);
        long long value = 0;
        char extra = ' ';

        if (!(number_input >> value)) {
            std::cerr << "无效整数: " << token << '\n';
            return 1;
        }

        if (number_input >> extra) {
            std::cerr << "多余字符: " << token << '\n';
            return 1;
        }

        bool seen = false;

        for (long long kept : nums) {
            if (kept == value) {
            seen = true;
            break;
          }
         }

       if (!seen) {
        nums.push_back(value);
       }
    }

    bool first = true;
for (long long value : nums) {
    if (!first) {
        std::cout << ' ';
    }
    std::cout << value;
    first = false;
}
std::cout << '\n';
}