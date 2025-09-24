#include <iostream>
#include <string>

int main() {
    std::string word = "supercalifragilisticexpialidocious";
    std::cout << "The string is '" << word << "'" << std::endl;

    size_t index = 0;
    do {
        std::cout << "Enter index to show letter or 9999 to exit: ";
        if (std::cin >> index) {
            if (index != 9999) {
                try {
                    std::cout << word.at(index) << " is the letter at index " << index << std::endl;
                }
                catch (const std::out_of_range& e) {
                    std::cout << "out of range: " << e.what() << std::endl;
                }
                catch (...) {
                    std::cout << "unknown exception" << std::endl;
                }
            }
        } else {
            std::cout << "bad input, exiting" << std::endl;
            index = 9999;
        }
    } while (index != 9999);

    return 0;
}
