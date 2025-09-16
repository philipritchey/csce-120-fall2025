#include <iostream>
#include <string>
#include <vector>

#define DEBUG(X) std::cout << "(" << __func__ << ":" << __LINE__ << ") [DEBUG] " << #X << " = " << X << std::endl;

std::ostream& operator<<(std::ostream&, const std::vector<int>&);

// swap neighboring elements at indicies `i` and `i+1`
void bubble(std::vector<int> numbers, unsigned int i) {
    DEBUG(numbers)
    int swap_value = numbers.at(i);
    numbers.at(i) = numbers.at(i+1);
    numbers.at(i+1) = swap_value;
    DEBUG(numbers)  // why is the vector updated here, but not in the calling function?  ...hmm?
}

int main() {
    std::vector<int> numbers{1,2};

    // expect bubble({1,2}, 0) to update vector to {2,1}
    bubble(numbers, 0);
    if (numbers.size() == 2 and numbers.front() == 2 and numbers.back() == 1) {
        std::cout << "[PASS] swap {1,2} -> {2,1}\n";
    } else {
        std::cout << "[FAIL] expected swap {1,2} -> {2,1}, got "<<numbers<<"\n";
    }
    
    return 0;
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
