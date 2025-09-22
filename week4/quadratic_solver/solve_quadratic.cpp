#include <vector>
#include <cmath>

// solve ax^2 + bx + c = 0 given coefficients a,b,c
// return a list of real-valued roots
std::vector<double> solve_quadratic(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                // there are infinite solutions
                // represented by {0, 0, 0}
                // distinguishes value from 0, 1, or 2 root cases
               return {0, 0, 0};
            }
            // else, there are 0 solutions
            return {};
        }
        // else, solve a linear equation
        return {-c/b};
    }
    // else, solve a quadratic equation
    // force a -> 1 by dividing equation by a
    b /= a;
    c /= a;
    a = 1;
    double d = b*b - 4*c;
    if (d < 0) {
        // imaginary roots -> no real roots
        return {};
    }
    // else, 2 real roots
    return {(-b + sqrt(d))/2, (-b - sqrt(d))/2};
}
