#include <iostream>

int main() {
    int x = 5;
    int y = 10;

    int* p = &x;
    int* q = &y;

    *p = 2;
    int z = *q - x;

    std::cout << z;

    return 0;
}
