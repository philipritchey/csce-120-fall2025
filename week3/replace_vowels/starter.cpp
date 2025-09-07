#include <iostream>
#include <string>

// replace all vowels in the input string with "#"
std::string replace_vowels(std::string str) {
    // TODO(student)
    // find the position of the first vowel
    // while a vowel was found
        // replace the vowel with "#"
        // find the position of the next vowel
    // end-while
    return str;
}

// prompts the user for input and returns a string containing the user's response
std::string input(std::string prompt) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int main() {
    std::string line = input("Enter a line of text:\n");
    std::string line_no_vowels = replace_vowels(line);
    std::cout << line_no_vowels << std::endl;

    return 0;
}