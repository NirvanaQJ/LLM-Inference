#include <iostream>
#include <thread>
#include <mutex>
long long counter = 0;
const int increments = 0;
std::mutex counter_mutex;
void worker() {
    for (int i = 0; i < increments; ++i) {
        std::lock_guard<std::mutex> guard(counter_mutex);
        ++counter;
    }
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << "actual=" << counter << '\n';
}
