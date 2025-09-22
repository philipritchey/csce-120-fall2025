#include <iostream>
#include <stdexcept>
#include <vector>

// returns the value of a + b
int16_t add(int16_t a, int16_t b) {
    if (a + b > INT16_MAX || a + b < INT16_MIN) {
        // TODO(student): what to do?
    }
    return a + b;
}

// returns the first index of value in number
size_t find(const std::vector<int>& numbers, int value) {
    for (size_t index = 0; index < numbers.size(); index++) {
        if (numbers.at(index) == value) {
            return index;
        }
    }
    // TODO(student): what to do?
}

int get_choice() {
    int choice;
    std::cin >> choice;
    while (std::cin.fail()) {
        // TODO(student): what to do?
    }
    return choice;
}

int main() {
    return 0;
}
