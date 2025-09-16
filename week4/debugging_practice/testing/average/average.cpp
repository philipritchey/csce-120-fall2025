#include <iostream>
#include <string>
#include <vector>

std::string input(const std::string&);
std::vector<int> random_integers(int, unsigned int);
void print_vector(const std::string&, const std::vector<int>&);
int sum(const std::vector<int>&);

int main() {
    // ask for how many numbers to use
    unsigned int how_many_numbers;
    try {
        how_many_numbers = std::stoi(input("How many numbers? "));
    } catch (const std::invalid_argument& _) {
        std::cout << "Invalid input, exiting." << std::endl;
        return -1;
    }

    std::vector<int> numbers = random_integers(10, how_many_numbers);
    print_vector("numbers", numbers);
    std::cout << "average = " << sum(numbers) / numbers.size() << std::endl;

    return 0;
}

// prompt the user for input, return one line of input as a string
std::string input(const std::string& prompt = "") {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}

// fill vector with `count` random integers between 0 and `upper`
std::vector<int> random_integers(int upper, unsigned int count) {
    std::vector<int> numbers;
    for (unsigned int i = 0; i < count; ++i) {
        numbers.push_back(rand() % upper);
    }
    return numbers;
}

// print the contents of the vector
void print_vector(const std::string& name, const std::vector<int>& numbers) {
    std::cout << name << " = [";
    for (int number : numbers) {
        std::cout << " " << number;
    }
    std::cout << " ]";
    std::cout << std::endl;
}

// sum the values in the vector
int sum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}
