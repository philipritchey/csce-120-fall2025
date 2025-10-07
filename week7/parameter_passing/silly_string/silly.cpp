#include <iostream>
#include <string>
#include <ctime>

/**
 * return the middle of the string
 * @param str the string
 * @returns the middle third of the string
 */
std::string get_middle_third(std::string& str) {
    std::string retStr;

    size_t third = str.size() / 3;
    for (size_t i = third; i < (third * 2); ++i) {
        retStr += str.at(i);
    }

    // TODO(us): fix this side effect
    str.at(str.size() / 2) = '?';

    return retStr;
}

/**
 * randomly swap characters from the first half of the string with the second half
 * @param str the string
 */
void shuffle(std::string& str) {
    for (size_t i = 0; i < str.size() / 2; ++i) {
        size_t index = random() % (str.size() / 2);

        char temp = str.at(index);
        str.at(index) = str.at(str.size() - 1 - index);
        str.at(str.size() - 1 - index) = temp;
    }
}

std::string input(const std::string& prompt) {
    std::cout << prompt;
    std::string str;
    std::getline(std::cin, str);
    return str;
}

int main() {
    srand(time(NULL));

    std::string str = input("Enter a string: ");

    shuffle(str);

    std::cout << "String: " << str << std::endl;
    std::cout << "Middle third: " << get_middle_third(str) << std::endl;
    std::cout << "String: " << str << std::endl;

    return 0;
}
