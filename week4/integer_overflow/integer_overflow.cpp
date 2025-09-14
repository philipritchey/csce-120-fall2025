#include <iostream>
#include <string>

void print(const std::string& = "");

int main() {
    print("A char is 1 byte (8 bits) and can hold values in the range [-128, 127]");
    print("Watch what happens when we increment a char beyond its range:");
    char c = 123;
    for (int j = 0; j < 10; ++j) {
        print("c = " + std::to_string(c));
        c += 1;
    }
    print();

    print("An unsigned char is 1 byte (8 bits) and can hold values in the range [0, 255]");
    print("Watch what happens when we increment an unsigned char beyond its range:");
    unsigned char uc = 251;
    for (int j = 0; j < 10; ++j) {
        print("uc = " + std::to_string(uc));
        uc += 1;
    }
    print();

    print("An int32_t is an integer that is 4 bytes (32 bits) and can hold values in the range ["+std::to_string(INT32_MIN)+", "+std::to_string(INT32_MAX)+"]");
    print("Watch what happens when we increment a 32-bit integer beyond its range:");
    int32_t i = INT32_MAX - 4;
    for (int j = 0; j < 10; ++j) {
        print("i = " + std::to_string(i));
        i += 1;
    }
    print();

    print("Integer overflow can lead to some weird (and undefined) behavior...");
    print("For example:");
    int32_t a = INT32_MAX;
    print(std::to_string(a) + " + " + std::to_string(a) + " = " +  std::to_string(a + a));
    a = (INT32_MAX >> 1) + 1;
    print(std::to_string(a) + " * " + std::to_string(a) + " = " +  std::to_string(a * a));
    a = INT32_MIN;
    int32_t b = INT32_MAX;
    print(std::to_string(a) + " - " + std::to_string(b) + " = " +  std::to_string(a - b));
    a = 0;
    print("a = " + std::to_string(a));
    for (int j = 1; j <= 13; ++j) {
        a = 10*a + (j % 10);
        print("a = " + std::to_string(a));
    }
    print();

    print("Next: * compile the program with -fsanitize=undefined");
    print("      * what happens when you run the program?");
    print();

    return 0;
}

// print a string
void print(const std::string& str) {
    std::cout << str << std::endl;
}
