// main.cpp
#include <iostream>
#include <vector>
#include "collatz.h"

int main() {
    unsigned n;
    std::cout << "n = ";
    std::cin >> n;
    std::vector<unsigned> v = collatz(n);
    std::cout << "collatz("<<n<<") = ";
    print_vector(v);
    std::cout << std::endl;
    return 0;
}
