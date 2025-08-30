// PSEUDOCODE
/*
to compute the average of a series of numbers:
assuming:
  * non-negative
  * floating point
  * 1 value per line
  * terminated by a negative value
  * on standard input

let sum = 0
let n = 0
read a value
while the value is non-negative, do:
    n = n + 1
    sum = sum + value
    read a value
end-while
return sum / n

to read a value:
do:
    read a line
    try to convert line to a double value
while failed to convert line to a double value
return double value
*/

// PROGRAM
#include <iostream>

double read_a_value() {
    double value;
    bool failed_to_read_a_value = false;
    do {
        failed_to_read_a_value = false;
        // read a line
        std::string line;
        std::getline(std::cin, line);
        try {
            // try to convert line (string) to double
            value = std::stod(line);
        } catch (std::invalid_argument& err) {
            // failed to convert line to double value
            std::cout << "[WARN] skipping invalid value" << std::endl;
            failed_to_read_a_value = true;
        }
    } while (failed_to_read_a_value);
    return value;
}

double compute_average() {
    double sum_of_values = 0;
    int number_of_values = 0;
    double value = read_a_value();
    while (value >= 0) {
        number_of_values += 1;
        sum_of_values += value;
        value = read_a_value();
    }
    return sum_of_values / number_of_values;
}

int main() {
    double average = compute_average();
    std::cout << "average: " << average << std::endl;
    return 0;
}
