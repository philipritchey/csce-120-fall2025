#include <iostream>

// this is what we ended up with in class

int main() {
    // to find the maximum value of 3 floating-point numbers:
    // read the first value
    double first_value = 0;
    std::cin >> first_value;
    // if failed to read a value, then end the program with an error
    if (std::cin.fail()) {
        std::cout << "[ERROR] invalid input, try again next time." << std::endl;
        return 1;
    }
    // read the second value
    double second_value = 0;
    std::cin >> second_value;
    // if failed to read a value, then end the program with an error
    if (std::cin.fail()) {
        std::cout << "[ERROR] invalid input, try again next time." << std::endl;
        return 1;
    }
    // read the third value
    double third_value = 0;
    std::cin >> third_value;
    // if failed to read a value, then end the program with an error
    if (std::cin.fail()) {
        std::cout << "[ERROR] invalid input, try again next time." << std::endl;
        return 1;
    }

    // find the max of first, second, and third values

    // to find the max of 2 numbers a, b:
    // if a >= b, then max is a
    // else max is b
    double max = first_value;
    if (second_value > max) {
        max = second_value;
    }

    // to find the max of 3 numbers a, b, c:
    // find max of max(a, b) and c
    if (third_value > max) {
        max = third_value;
    }

    // print the max
    std::cout << "max: " << max << std::endl;

    return 0;
}
