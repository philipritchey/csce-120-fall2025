#include <iostream>
#include <vector>

int main() {
    std::vector<int> vector;
    // what kind of data is stored in the vector?

    // what are the contents of the vector after each step?
    vector.push_back(8);
    vector.push_back(6);
    vector.push_back(7);
    vector.push_back(5);
    // what is the size of the vector?

    // what will be printed?
    std::cout << "size: " << vector.size() << std::endl;
    std::cout << "front: " << vector.front() << std::endl;
    std::cout << "back: " << vector.back() << std::endl;
    std::cout << "at 2: " << vector.at(2) << std::endl;
    // std::cout << "at -1: " << vector.at(-1) << std::endl;

    // what does this do?
    vector.pop_back();

    // what will be printed?
    std::cout << "size: " << vector.size() << std::endl;
    std::cout << "back: " << vector.back() << std::endl;

    return 0;
}
