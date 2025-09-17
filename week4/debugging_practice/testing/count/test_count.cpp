#include <iostream>
#include <vector>

// i'm just being fancy...
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"

std::ostream& operator<<(std::ostream&, const std::vector<int>&);

// count how many times `x` occurs in `numbers`
unsigned count(const std::vector<int>& numbers, int x) {
    unsigned cnt = 0;
    for (int number : numbers) {
        if (number = x) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    std::vector<int> numbers{1,1,1,2,3,3};
    std::vector<int> xs{1,2,3};
    std::vector<unsigned> expected_counts{3,1,2};
    unsigned fail_cnt = 0;
    unsigned pass_cnt = 0;
    for (unsigned i = 0; i < 3; ++i) {
        int x = xs.at(i);
        unsigned expected = expected_counts.at(i);
        unsigned actual = count(numbers, x);
        if (actual != expected) {
            std::cout << RED << "[FAIL] expected count("<<numbers<<", "<<x<<") to be "<<expected<<", got "<<actual<< RESET << "\n";
            fail_cnt++;
        } else {
            pass_cnt++;
        }
    }
    // so fancy...
    std::cout << BOLD << (pass_cnt + fail_cnt) << " tests" << RESET << "\n";
    if (pass_cnt) {
        std::cout << GREEN << pass_cnt << " passing" << RESET << "\n";
    }
    if (fail_cnt) {
        std::cout << RED << fail_cnt << " failing" << RESET << "\n";
    }
    return fail_cnt;
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
