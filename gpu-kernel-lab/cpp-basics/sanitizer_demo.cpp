#include <iostream>
#include <memory>

int main() {
    int* watch = nullptr;

    {
        auto owner = std::make_unique<int>(7);
        watch = owner.get();

        std::cout << *watch << '\n';  // 在 owner 仍存活时读取。
    }
}
