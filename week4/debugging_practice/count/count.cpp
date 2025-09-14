#include <iostream>
#include <string>
#include <vector>

std::vector<int> random_integers(int, unsigned int);
void print_vector(const std::string&, const std::vector<int>&);
std::string input(const std::string&);
unsigned count(const std::vector<int>&, int);

int main() {
    std::vector<int> numbers = random_integers(10, 10);
    print_vector("numbers", numbers);

    // ask for a number to search for
    int x;
    try {
        x = std::stoi(input("Which number to count? "));
    } catch (const std::invalid_argument& _) {
        std::cout << "Invalid input, exiting." << std::endl;
        return -1;
    }

    std::cout << count(numbers, x) << " instances of " << x << std::endl;

    return 0;
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

// prompt the user for input, return one line of input as a string
std::string input(const std::string& prompt = "") {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}

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
