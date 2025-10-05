#include <iostream>
#include <string>

void print(const int& x, const std::string& label) {
    std::cout << label << ":";
    std::cout << "  address = " << &x;
    std::cout << "  value = " << x;
    std::cout << std::endl;
}

void print(const int* x, const std::string& label) {
    std::cout << label << ":";
    std::cout << "  address = " << &x;
    std::cout << "  value = " << x;
    std::cout << "  points to = " << *x;
    std::cout << std::endl;
}

int main() {
    // declare an integer pointer but don't initialize
    int* k;
    std::cout << "use an int pointer without initializing it" << std::endl;
    print(k, "k");

    // initialize it to a new int
    std::cout << std::endl << "create a new int and set the int pointer to point to it" << std::endl;
    int j = 10;
    k = &j;
    print(j, "j");
    print(k, "k");

    // set it to the nullptr
    std::cout << std::endl << "set the int pointer to be the nullptr and attempt to use it" << std::endl;
    k = nullptr;
    print(k, "k");

    return 0;
}
