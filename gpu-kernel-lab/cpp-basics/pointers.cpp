#include <iostream>

void swap_value(int x, int y) {
    std::cout << "inside: &x=" << &x << ", &y=" << &y << '\n';

    int temp = x;
    x = y;
    y = temp;

    std::cout << "inside: x=" << x << ", y=" << y << '\n';
}


void swap_pointer(int* x, int* y) {
    std::cout << "pointer: x=" << x << ", y=" << y << '\n';
    std::cout << "pointer: &x=" << &x << ", &y=" << &y << '\n';

    int temp = *x;
    *x = *y;
    *y = temp;

    std::cout << "pointer: *x=" << *x << ", *y=" << *y << '\n';
}

void swap_reference(int& x, int& y) {
    std::cout << "reference: &x=" << &x << ", &y=" << &y << '\n';

    int temp = x;
    x = y;
    y = temp;

    std::cout << "reference: x=" << x << ", y=" << y << '\n';
}
int main() {
    int a = 3;
    int b = 8;

    std::cout << "before: a=" << a << ", b=" << b << '\n';
    std::cout << "main: &a=" << &a << ", &b=" << &b << '\n';

    swap_value(a, b);

   std::cout << "after value: a=" << a << ", b=" << b << '\n';

    swap_pointer(&a, &b);

    std::cout << "after pointer: a=" << a << ", b=" << b << '\n';

    swap_reference(a, b);

    std::cout << "after reference: a=" << a << ", b=" << b << '\n';
}