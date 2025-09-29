#include <iostream>
#include <sstream>
#include <string>

int main() {
    // read in expression
    std::cout << "Enter the expression to calculate in one line: " << std::endl;
    std::string line;
    std::getline(std::cin, line);

    // extract operands and operator using a std::istringstream
    double first_number = 0, second_number = 0;
    char op = ' ';

    std::istringstream iss(line);
    // std::cout << "TODO: extract <first_number> <op> <second_number> from iss" << std::endl;
    iss >> first_number >> op >> second_number;

    // compute the result of the question based on op
    double result = 0;
    // std::cout << "TODO: compute result based on op symbol, allowed symbols are +, -, *, /" << std::endl;
    switch (op) {
        case '+':
            result = first_number + second_number;
            break;
        case '-':
            result = first_number - second_number;
            break;
        case '*':
            result = first_number * second_number;
            break;
        case '/':
            if (second_number == 0) {
                std::cerr << "error: divide by zero" << std::endl;
                return 1;
            }
            result = first_number / second_number;
            break;
        default:
            std::cerr << "error: invalid operator" << std::endl;
            return 2;
    }

    // output result
    std::cout << "result: " << result << std::endl;

    return 0;
}
