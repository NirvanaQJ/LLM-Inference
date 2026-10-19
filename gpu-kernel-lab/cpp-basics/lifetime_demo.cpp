#include <iostream>

struct Trace {
    Trace() {
        std::cout << "构造\n";
    }

    ~Trace() {
        std::cout << "析构\n";
    }
};

int main() {
    Trace t;
    {
        std::cout << "块内\n";
    }
    std::cout << "块外\n";
}