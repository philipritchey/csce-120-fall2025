#include <iostream>
#include <vector>
#include "solve_quadratic.cpp"

#define RED(X) "\033[31;1m" X "\033[0m"
#define GREEN(X) "\033[32;1m" X "\033[0m"

// overloaded insertion operator to pretty-print vector of doubles
std::ostream& operator<<(std::ostream&, const std::vector<double>&);

int main() {
    // a=b=c=0 -> infinite roots (represented by {0, 0, 0})
    {
        std::vector roots = solve_quadratic(0, 0, 0);
        if (roots.size() == 3 and roots.at(0) == 0 and roots.at(1) == 0 and roots.at(2) == 0) {
            std::cout << GREEN("[PASS] 0 = 0") << std::endl;
        } else {
            std::cout << RED("[FAIL] expected roots of 0 = 0 to be {0, 0, 0}") << std::endl;
            std::cout << "       got " << roots << std::endl;
        }
    }

    // a=b=0, c != 0 -> no roots
    {
        std::vector roots = solve_quadratic(0, 0, 1);
        if (roots.empty()) {
            std::cout << GREEN("[PASS] 1 = 0") << std::endl;
        } else {
            std::cout << RED("[FAIL] expected roots of 1 = 0 to be {}") << std::endl;
            std::cout << "       got " << roots << std::endl;
        }
    }

    // a=0, b != 0 -> 1 real root (linear equation)
    {
        std::vector roots = solve_quadratic(0, 2, -1);
        if (roots.size() == 1 and roots.at(0) == 0.5) {
            std::cout << GREEN("[PASS] 2x - 1 = 0") << std::endl;
        } else {
            std::cout << RED("[FAIL] expected roots of 2x - 1 to be {0.5}") << std::endl;
            std::cout << "       got " << roots << std::endl;
        }
    }

    // b^2 - 4ac < 0 -> no real roots
    {
        std::vector roots = solve_quadratic(1, 0, 1);
        if (roots.empty()) {
            std::cout << GREEN("[PASS] x^2 + 1 = 0") << std::endl;
        } else {
            std::cout << RED("[FAIL] expected roots of x^2 + 1 to be {}") << std::endl;
            std::cout << "       got " << roots << std::endl;
        }
    }

    // b^2 - 4ac = 0 -> 2 real roots (1 root of multiplicity 2)
    {
        std::vector roots = solve_quadratic(1, -4, 4);
        if (roots.size() == 2 and roots.at(0) == 2 and roots.at(1) == 2) {
            std::cout << GREEN("[PASS] x^2 - 4x + 4 = 0") << std::endl;
        } else {
            std::cout << RED("[FAIL] expected roots of x^2 - 4x + 4 = 0 to be {2, 2}") << std::endl;
            std::cout << "       got " << roots << std::endl;
        }
    }

    // b^2 - 4ac > 0 -> 2 real roots
    {
        std::vector roots = solve_quadratic(1, 0, -4);
        if (roots.size() == 2 and roots.at(0) == 2 and roots.at(1) == -2) {
            std::cout << GREEN("[PASS] x^2 - 4 = 0") << std::endl;
        } else {
            std::cout << RED("[FAIL] expected roots of x^2 - 4 = 0 to be {2, -2}") << std::endl;
            std::cout << "       got " << roots << std::endl;
        }
    }

    // handle floating-point coefficients
    {
        std::vector roots = solve_quadratic(1/2.0, 4/15.0, 1/30.0);
        if (roots.size() == 2 and std::abs(roots.at(0) - -1/5.0) < 1e-8 and std::abs(roots.at(1) - -1/3.0) < 1e-8) {
            std::cout << GREEN("[PASS] (1/2)x^2 + (4/15)x + 1/30 = 0") << std::endl;
        } else {
            std::cout << RED("[FAIL] expected roots of (1/2)x^2 + (4/15)x + 1/30 = 0 to be {-1/5, -1/3}") << std::endl;
            std::cout << "       got " << roots << std::endl;
        }
    }
    return 0;
}

std::ostream& operator<<(std::ostream& os, const std::vector<double>& v) {
    os << "{";
    bool first = true;
    for (double d : v) {
        if (!first) {
            os << ", ";
        }
        os << d;
        first = false;
    }
    os << "}";
    return os;
}