// collatz.cpp
#include <iostream>
#include <vector>

// returns a vector containing the collatz sequence of n
std::vector<unsigned> collatz(unsigned n) {
    std::vector<unsigned> sequence;
    sequence.push_back(n);
    while (n > 1) {
        if (n % 2 == 0) {
            // n is even
            n /= 2;
        } else {
            // n is odd
            n = 3*n + 1;
        }
        sequence.push_back(n);
    }
    return sequence;
}

// prints the square bracketed, comma-separated contents of the vector to standard output
void print_vector(const std::vector<unsigned>& vector) {
    std::cout << "[";
    if (!vector.empty()) {
        // print first value on it's own
        std::cout << vector.front();
        // print every remaining value with a comma in front
        for (size_t i = 1; i < vector.size(); ++i) {
            std::cout << "," << vector.at(i);
        }
    }
    std::cout << "]";
}
