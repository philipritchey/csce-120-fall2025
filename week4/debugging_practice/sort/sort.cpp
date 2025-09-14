#include <iostream>
#include <string>
#include <vector>

std::vector<int> random_integers(int, unsigned int);
void print_vector(const std::string&, const std::vector<int>&);
std::vector<int> bubble_sort(std::vector<int>);

int main() {
    std::vector<int> numbers = random_integers(20, 10);
    std::vector<int> sorted = bubble_sort(numbers);
    print_vector("numbers", numbers);
    print_vector(" sorted", sorted);
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

// swap neighboring elements at indicies `i` and `i+1`
void bubble(std::vector<int> numbers, unsigned int i) {
    int swap_value = numbers.at(i);
    numbers.at(i) = numbers.at(i+1);
    numbers.at(i+1) = swap_value;
}

// bubble sort the vector
std::vector<int> bubble_sort(std::vector<int> numbers) {
    for (unsigned int i = 0; i < numbers.size() - 1; ++i) {
        for (unsigned int j = 0; j < numbers.size() - i - 1; ++j) {
            if (numbers.at(j) > numbers.at(j+1)) {
                bubble(numbers, j);
            }
        }
    }
    return numbers;
}
