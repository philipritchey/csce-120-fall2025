#include <iostream>
#include <limits>

const unsigned int MAX_LINES = 80;

int main() {
    unsigned int no_lines;
    std::cout << "Please provide a number of lines to print the stair-case pattern: ";
    std::cin >> no_lines;

    // TODO(student): handle invalid input:
    //                * reset the stream back to good
    //                  * clear the stream state
    //                  * clear the buffer
    //                * re-prompt
    //                until input is valid

    bool valid = false;
    while (!valid) {
        valid = true;
        if (std::cin.fail()) {
            // failed to read something 
            valid = false;

            if (std::cin.eof()) {
                // reached end of stream (no hope to find more)
                std::cout << "eof: no more input. goodbye." << std::endl;
                return -1;
            }
            std::cout << "fail: invalid input. try again." << std::endl;
            // reset the stream to a good state and discard contents of buffer (up to newline)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // reprompt
            std::cout << "Please provide a number of lines to print the stair-case pattern: ";
            std::cin >> no_lines;
        } else {
            // try to read one more char (expect to fail on valid input)
            int c = std::cin.get();
            if (c != '\n' && !std::cin.fail()) {
                // successfully read something extra, which means the first thing we got was not strictly valid
                valid = false;
                std::cout << "strict: invalid input. try again." << std::endl;

                // reset the stream to a good state and discard contents of buffer (up to newline)
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                // reprompt
                std::cout << "Please provide a number of lines to print the stair-case pattern: ";
                std::cin >> no_lines;
            } else {
                // bounds check
                if (no_lines > MAX_LINES) {
                    valid = false;
                    std::cout << "bounds: invalid input. try again." << std::endl;
                    
                    // don't mess with the stream state because it didn't change
                    
                    // reprompt
                    std::cout << "Please provide a number of lines to print the stair-case pattern: ";
                    std::cin >> no_lines;
                }
            }
        }
    }

    for (unsigned int i = 1; i <= no_lines ; ++i) {
        for (unsigned int j = 1 ; j <= i ; ++j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    return 0;
}
