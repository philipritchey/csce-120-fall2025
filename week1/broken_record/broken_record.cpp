#include <iostream>

// `void` means "returns nothing"
void use_a_for_loop() {
    // do something 10 times
    for (int i = 0; i < 10; i++) {
        // something
    }
}

void use_a_while_loop() {
    // do something 10 time
    int i = 0;
    while (i < 10) {
        // something
        i++;  // shorthand for i = i + 1
    }
}

void use_a_do_while_loop() {
    // do something at least once and 10 times
    int i = 0;
    do {
        // something
        i++;
    } while (i < 10);
}

int main() {
    // print Howdy! 29 times
    for (int i = 0; i < 29; i++) {
        std::cout << "Howdy!" << std::endl;
    }
    return 0;
}
