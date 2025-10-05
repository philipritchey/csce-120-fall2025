#include <iostream>

// swaps the values of `a` and `b`
void swap(int a, int b) {
    // TODO(student): update this function so the swap persists outside the function
}

int main() {
    int x = 11;
    int y = 7;

    std::cout << "before swap: " << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    swap(x, y);

    std::cout << "after swap: " << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    return 0;
}
