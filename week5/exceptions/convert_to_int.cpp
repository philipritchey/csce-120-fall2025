#include <iostream>
#include <string>

int main() {
    std::string term;

    do {
        std::cout << "Enter string to convert to an integer or '.' to exit: ";
        std::cin >> term;

        if (term != ".") {
            // the following code may throw an exception
            int value = std::stoi(term);
            std::cout << term << " times 2 is " << (value * 2) << std::endl;
        }
    } while (term != ".");

    return 0;
}
