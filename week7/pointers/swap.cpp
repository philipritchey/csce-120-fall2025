#include <iostream>

void print(const int& x, const int& y, const int* p1, const int* p2) {
    std::cout << "x: " << x << " with address " << &x << std::endl;
    std::cout << "y: " << y << " with address " << &y << std::endl;

    std::cout << "p1: " << p1 << " points to " << *p1 << std::endl;
    std::cout << "p2: " << p2 << " points to " << *p2 << std::endl;

    std::cout << std::endl;
}

int main() {
    // create 2 integers
    int x = 9;
    int y = 5;

    // create 2 pointers to them
    int* p1 = &x;
    int* p2 = &y;

    std::cout << "before swap:" << std::endl;
    print(x, y, p1, p2);

    std::cout << "swapping pointers:" << std::endl;
    int* temp = p1;
    p1 = p2;
    p2 = temp;
    print(x, y, p1, p2);

    return 0;
}
