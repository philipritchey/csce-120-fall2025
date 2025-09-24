#include <iostream>

#define caught(x) std::cout << __func__ << " caught a " << x << std::endl;
#define here std::cout << __func__ << ":" << __LINE__ << std::endl;

void f3() {
    here
    throw 8;
    here  // will not be reached
}

void f2() {
    here
    try {
        f3();
        here  // will not be reached
    }
    catch (int err) { caught(err) }
    here
    throw 6;
    here  // will not be reached
}

void f1() {
    here
    try {
        f2();
        here  // will not be reached
    }
    catch (int err) { caught(err) }
    here
    throw 7;
    here  // will not be reached
}

int main() {
    here
    try {
        f1();
        here  // will not be reached
    }
    catch (int err) { caught(err) }
    here
}
