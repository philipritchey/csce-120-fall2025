#include <iostream>
#include <string>

#define start std::cout << padding << "-- start of " << __func__ << " --" << std::endl;
#define end std::cout << padding << "-- end of " << __func__ << " --" << std::endl;

// pass along padding std::string so easier to see nested function calls
void A(bool cause_exception, const std::string& padding);
void B(bool cause_exception, const std::string& padding);
void C(bool cause_exception, const std::string& padding);
void D(bool cause_exception, const std::string& padding);

int main() {
    std::string padding = "";
    start

    std::cout << "There are a series of nested function calls. A->B->C->D" << std::endl;
    std::cout << "Would you like the function D to throw an exception? y or n" << std::endl;
    char input;
    std::cin >> input;

    if (std::tolower(input) == 'y') {
        A(true, padding + "  ");
    } else if (std::tolower(input) == 'n') {
        A(false, padding + "  ");
    } else {
        std::cout << "invalid option, exiting." << std::endl;
    }

    end
    return 0;
}


void A(bool cause_exception, const std::string& padding) {
    start

    B(cause_exception, padding + "  ");

    end
}


void B(bool cause_exception, const std::string& padding) {
    start

    try {
        C(cause_exception, padding + "  ");
    } catch (const std::out_of_range& err) {
        std::cout << padding << "B: caught an out_of_range exception from C" << std::endl;
        std::cout << padding << "   what(): " << err.what() << std::endl;
    }

    end
}


void C(bool cause_exception, const std::string& padding) {
    start

    D(cause_exception, padding + "  ");

    end
}


void D(bool cause_exception, const std::string& padding) {
    start

    if (cause_exception) {
        std::cout << padding << "D is calling a function that throws an exception" << std::endl;
        std::string s = "hi";
        s.at(3);
    } else {
        std::cout << padding << "D is doing nothing" << std::endl;
    }

    end
}
