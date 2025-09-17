#include <iostream>
#include "functions.h"

int main() {

    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << trim(line) << "\n";
    }

    return 0;
}
