#include <iostream>
#include <string>

int main() {
    // declare a string
    std::string str = "Howdy!";
    std::cout << "My string is: " << str << std::endl;
    std::cout << "The first charater is " << str.at(0) << std::endl << std::endl;

    // declare a string pointer
    std::string* strPtr = &str;
    std::cout << "My string pointer is: " << strPtr << std::endl;
    std::cout << "The string it points to is: " << *strPtr << std::endl;
    std::cout << "The first charater is " << (*strPtr).at(0) << std::endl;

    // another way to dereference the pointer
    std::cout << "The first charater is " << strPtr->at(0) << std::endl;

    // modify the string through the pointer
    std::cout << std::endl << "Updating the first character through the string pointer:" << std::endl;
    strPtr->at(0) = 'R';
    std::cout << "My string is: " << str << std::endl;
    std::cout << "My string pointer is: " << strPtr << std::endl;
    std::cout << "The string it points to is: " << *strPtr << std::endl;

    // modify the string directly
    std::cout << std::endl << "Updating the first character through the string directly:" << std::endl;
    str.at(0) = 'D';
    std::cout << "My string is: " << str << std::endl;
    std::cout << "My string pointer is: " << strPtr << std::endl;
    std::cout << "The string it points to is: " << *strPtr << std::endl;

    return 0;
}
