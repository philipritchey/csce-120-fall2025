#include <iostream>
#include <vector>
#include <cmath>

#define DEBUG(X) std::cout << "(" << __func__ << ":" << __LINE__ << ") [DEBUG] " << #X << " = " << X << std::endl;

std::ostream& operator<<(std::ostream&, const std::vector<int>&);

int sum(const std::vector<int>&);

int main() {
    std::vector<int> numbers{1,2};

    DEBUG(sum(numbers))
    DEBUG(numbers.size())
    // expect average of {1,2} to be 1.5
    double expected_average = 1.5;
    double actual_average = sum(numbers) / numbers.size();
    if (std::abs(actual_average - expected_average) <= 1e-6) {
        std::cout << "[PASS] average of "<<numbers<<" = "<<expected_average<<"\n";
    } else {
        std::cout << "[FAIL] expected average of "<<numbers<<" to be "<<expected_average<<", got "<<actual_average<<"\n";
    }
    // why is 3 / 2 = 1?
    DEBUG(typeid(sum(numbers)).name())    // i := int
    DEBUG(typeid(numbers.size()).name())  // m := unsigned long
    DEBUG(typeid(sum(numbers)/numbers.size()).name())  // m := unsigned long

    return 0;
}

// sum the values in the vector
int sum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}

// pretty print vector into stream
std::ostream& operator<<(std::ostream& os, const std::vector<int>& numbers) {
    os << "{";
    bool first = true;
    for (int number : numbers) {
        if (not first) {
            os << ",";
        }
        first = false;
        os << number;
    }
    os << "}";
    return os;
}
