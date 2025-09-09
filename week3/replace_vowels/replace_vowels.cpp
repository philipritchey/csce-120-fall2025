#include <iostream>
#include <string>

// replace all vowels in the input string with "#"
std::string replace_vowels(std::string str) {
    const std::string VOWELS = "aeiouAEIOUyY";
    // find the position of the first vowel
    size_t pos = str.find_first_of(VOWELS);
    // while a vowel was found
    while (pos != std::string::npos) {
        // replace the vowel with "#"
        str.replace(pos, 1, "#");
        // find the position of the next vowel
        pos = str.find_first_of(VOWELS, pos+1);
    } // end-while
    return str;
}

// print a string
void print(const std::string& str, const std::string& end="\n", bool flush=false) {
    std::cout << str << end;
}

// prompt the user for input and return a string containing the user's response
std::string input(std::string prompt) {
    print(prompt, "");
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int main() {
    std::string line = input("Enter a line of text:\n");
    std::string line_no_vowels = replace_vowels(line);
    print("original: " + line);
    print(" changed: " + line_no_vowels);
    return 0;
}
