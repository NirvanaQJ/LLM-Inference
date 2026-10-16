#include <iostream>
#include <vector>

void print_values(const std::vector<int>& nums) {
    for (std::size_t i = 0; i <= nums.size(); ++i) {
        std::cout << nums.at(i) << '\n';
    }
}

int main() {
    std::vector<int> nums{4, 7, 9};
    print_values(nums);
    return 0;
}