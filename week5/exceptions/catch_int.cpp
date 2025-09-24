#include <iostream>

#define start std::cout << "-- start of " << __func__ << " --" << std::endl;
#define end std::cout << "-- end of " << __func__ << " --" << std::endl;

void throwing_function_a() {
    start

    // throw an int (just for fun make it even)
    throw 4;

    end
}


void throwing_function_b() {
    start

    // throw an int (just for fun make it odd)
    throw 5;

    end
}

bool is_even(int number) {
    return number % 2 == 0;
}

void error_message(int errorCode) {
    start

    if (is_even(errorCode)) {
        std::cout << "caught even error" << std::endl;
    } else {
        std::cout << "caught odd error" << std::endl;
    }

    end
}


int main() {
    start

    std::cout << "Select which throwing function you would like (1, 2, or 3): ";
    int version = 0;
    std::cin >> version;

    switch (version) {
    case 1:
        try {
            throwing_function_a();
        } catch (int e) {
            error_message(e);
        }
        break;
    case 2:
        try {
            throwing_function_b();
        } catch (int e) {
            error_message(e);
        }
        break;
    case 3:
        try {
            throwing_function_a();
            throwing_function_b();
        } catch (int e) {
            error_message(e);
        }
        break;
    default:
        std::cout << "Error, invalid choice." << std::endl;
    }

    end
}
