#include <iostream>
#include <string>
#include <sstream>

#define print(X) std::cout << #X << "=" << std::boolalpha << X << std::endl;

int main() {
    // read in a line of input, place in a istringstream
    std::cout << "Provide a line of input.\n";
    std::cout << "The code will attempt to extract an integer from it." << std::endl;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);

    int z = -99;
    iss >> z;

    print(z);
    print(iss.eof());
    print(iss.fail());
    print(iss.bad());
    print(iss.good());

    return 0;
}
