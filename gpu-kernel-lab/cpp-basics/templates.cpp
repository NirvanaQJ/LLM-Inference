#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
T my_min(T a, T b) {
    if (a < b) {
        return a;
    }
    return b;
}

template<typename T>
T my_max(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

template<typename T, typename Pred>
std::vector<T> filter_keep(const std::vector<T>& values, Pred keep) {
    std::vector<T> result;

    for (const T& value : values) {
        if (keep(value)) {
            result.push_back(value);
        }
    }

    return result;
}

struct Item {
    int value;
};

int main() {
    std::cout << my_min(8, 3) << '\n';
    std::cout << my_max(8, 3) << '\n';
    std::cout << my_min(2.5, 4.0) << '\n';
    std::cout << my_max(2.5, 4.0) << '\n';
    std::cout << my_min(3, 8) << ' ' << my_max(3, 8) << '\n';
    std::cout << my_min(-2, -7) << ' ' << my_max(-2, -7) << '\n';
    std::cout << my_min(5, 5) << ' ' << my_max(5, 5) << '\n';

    std::cout << my_min(4.0, 2.5) << ' ' << my_max(4.0, 2.5) << '\n';
    std::cout << my_min(-1.5, -3.5) << ' ' << my_max(-1.5, -3.5) << '\n';
    std::cout << my_min(2.5, 2.5) << ' ' << my_max(2.5, 2.5) << '\n';
    std::vector<int> values{-2, 0, 3, 1};

    auto is_positive = [](int x) {
        return x > 0;
    };

    auto positives = filter_keep(values, is_positive);

    std::cout << "positive: ";
    for (int value : positives) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
    std::vector<double> readings{-0.5, 0.0, 2.5, 0.5};

    auto positive_readings = filter_keep(readings, [](double x) {
        return x > 0.0;
    });

    std::cout << "double_positive: ";
    for (double value : positive_readings) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
    auto keep_double = [](double x) {
        return x > 0.0;
    };

    // int：空输入、全部保留、全部剔除
    assert(filter_keep(std::vector<int>{}, is_positive).empty());
    assert((filter_keep(std::vector<int>{3, 1}, is_positive)
        == std::vector<int>{3, 1}));
    assert(filter_keep(std::vector<int>{-2, 0}, is_positive).empty());

    // double：空输入、全部保留、全部剔除
    assert(filter_keep(std::vector<double>{}, keep_double).empty());
    assert((filter_keep(std::vector<double>{2.5, 0.5}, keep_double)
        == std::vector<double>{2.5, 0.5}));
    assert(filter_keep(std::vector<double>{-0.5, 0.0}, keep_double).empty());

    // 核对前面过滤过的原输入仍保持不变
    assert((values == std::vector<int>{-2, 0, 3, 1}));
    assert((readings == std::vector<double>{-0.5, 0.0, 2.5, 0.5}));

    std::cout << "filter checks PASS\n";
    Item first{8};
    Item second{3};
    std::cout << "item values min: "
        << my_min(first.value, second.value) << '\n';
}
