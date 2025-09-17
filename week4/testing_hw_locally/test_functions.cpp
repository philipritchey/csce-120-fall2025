#include <iostream>
#include <string>
#include "functions.h"

void test_trim();

int main() {
    test_trim();

    return 0;
}

void test_trim() {
    // expect trim(" hello ") to be "hello"
    std::string str = " hello ";
    std::string expected = "hello";
    std::string actual = trim(str);
    if (actual != expected) {
        std::cout << "[FAIL] expected trim(\"" << str << "\")\n";
        std::cout << "       to be \"" << expected << "\"\n";
        std::cout << "         got \"" << actual << "\"" << std::endl;
    } else {
        std::cout << "[PASS]" << std::endl;
    }
}