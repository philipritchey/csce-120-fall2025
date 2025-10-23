#include <iostream>

int main() {
    int x = 5;
    int y = 10;

    int* p = &x;
    int* q = new int(3);

    *p = 2;
    int z = *q - x;

    delete q;

    std::cout << z;

    return 0;
}
