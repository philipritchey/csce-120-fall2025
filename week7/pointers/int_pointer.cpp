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
    // declare two integers and initialize them
    std::cout << "declaring some integers:" << std::endl;
    std::cout << "  int i = 4;" << std::endl << "  int j = 5;" << std::endl;
    int i = 4;
    int j = 5;
    print(i, "i");
    print(j, "j");

    // declare an integer pointer and initialize to point to integer i
    std::cout << std::endl << "declaring a pointer that points to i:" << std::endl;
    std::cout << "  int* k = &i;" << std::endl;
    int* k = &i;
    print(i, "i");
    print(j, "j");
    print(k, "k");

    // update the integer pointer to point to integer j
    std::cout << std::endl << "updating the pointer to point to j:" << std::endl;
    std::cout << "  k = &j;" << std::endl;
    k = &j;
    print(i, "i");
    print(j, "j");
    print(k, "k");

    // update j directly
    std::cout << std::endl << "updating j directly:" << std::endl;
    std::cout << "  j = 10;" << std::endl;
    j = 10;
    print(i, "i");
    print(j, "j");
    print(k, "k");

    // update the data that k points to
    std::cout << std::endl << "updating the integer's value that k points to through k:" << std::endl;
    std::cout << "  *k = 15;" << std::endl;
    *k = 15;
    print(i, "i");
    print(j, "j");
    print(k, "k");

    return 0;
}
