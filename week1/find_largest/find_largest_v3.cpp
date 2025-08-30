#include <iostream>

// this is after playing a bit of code golf

double read_double();
double max3(double, double, double);

int main() {
    // to find the largest of three values:
    try {
        // read 3 values and find the max
        double max = max3(read_double(), read_double(), read_double());
        // print the max
        std::cout << "max: " << max << std::endl;
    } catch (std::invalid_argument& err) {
        std::cout << "[ERROR] invalid input, try again next time." << std::endl;
        return 1;
    }

    return 0;
}

// find the max of 2 numbers
double max2(double a, double b) {
    // if a >= b, then max is a
    if (a > b) {
        return a;
    }
    // else max is b
    return b;
}

// find the max of 3 numbers
double max3(double a, double b, double c) {
    return max2(max2(a, b), c);
}

// read a double from standard input
// throws `std::invalid_argument` on failure
double read_double() {
    double value = 0;
    std::cin >> value;
    if (std::cin.fail()) {
        throw std::invalid_argument("invalid input");
    }
    return value;
}
