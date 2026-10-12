#include <iostream>

int main() {
  long long total = 0;
  long long value=0;
    while(std::cin>> value) {
        total += value;
    }
  std::cout << total << std::endl;
}