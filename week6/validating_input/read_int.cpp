#include <iostream>
#include <limits>
#include <string>

int get_an_integer() {
    int val = 0;
    std::cout << "Enter an integer: ";
    std::cin >> val;
    return val;
}

int main() {
    int val = get_an_integer();

    while (!std::cin.fail()) {
        // data was successfully read
        std::cout << "You entered: " << val << std::endl;

        if (!std::cin.eof()) {
            // haven't reached the end (not so much for console, but for strings and files)
            // set all stream state bits to zero, buffer NOT cleared
            std::cin.clear();

            // clear the buffer of everything/make clean slate to read again
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // re-prompt
            val = get_an_integer();
        }
    }
    std::cout << "Invalid input, exiting." << std::endl;

    return 0;
}
