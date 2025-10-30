#include <iostream>
#include <cassert>

void push_back(int* values, const size_t capacity, size_t& length, int value) {
    if (values == nullptr) {
        throw std::invalid_argument("invalid: array is nullptr");
    }
    if (length == capacity) {
        throw std::invalid_argument("invalid: array is full");
    }
    if (length > capacity) {
        throw std::invalid_argument("invalid: length > capacity");
    }
    // add value to end of used portion
    values[length++] = value;
}

void pop_back(int* values, const size_t capacity, size_t& length) {
    if (values == nullptr) {
        throw std::invalid_argument("invalid: array is nullptr");
    }
    if (length == 0) {
        throw std::invalid_argument("invalid: array is empty");
    }
    if (length > capacity) {
        throw std::invalid_argument("invalid: length > capacity");
    }
    // decrement size of used portion
    length--;
}

void test_push_back() {
    // Given array = nullptr, capacity = 1, and length = 0
    // When I push back a value
    // Then I should catch an exception
    // And length should be 0
    size_t length = 0;
    try {
        const size_t capacity = 1;  // lies
        push_back(nullptr, capacity, length, 1);
        assert(false);  // FAIL
    } catch (...) { assert(length == 0); }

    // Given a full array (length = 1, capacity = 1)
    // When I push back a value
    // Then I should catch an exception
    // And length should be 1
    length = 1;
    try {
        int a[1] {1};
        const size_t capacity = 1;
        push_back(a, capacity, length, 2);
        assert(false);  // FAIL
    } catch (...) { assert(length == 1); }

    // Given an over-full array (length = 2, capacity = 1)
    // When I push back a value
    // Then I should catch an exception
    // And length should be 2
    length = 2;
    try {
        int a[1] {1};
        const size_t capacity = 1;
        push_back(a, capacity, length, 2);
        assert(false);  // FAIL
    } catch (...) { assert(length == 2); }

    // Given an empty array (length = 0, capacity = 3)
    // When I push back the value 7
    // Then length should be 1
    // And the array should contain {7}
    // When I push back the value 4
    // Then length should be 2
    // And the array should contain {7, 4}
    // When I push back the value 9
    // Then length should be 3
    // And the array should contain {7, 4, 9}
    try {
        int a[3] {-1, -2, -3};  // sentinel values
        const size_t capacity = 3;
        size_t length = 0;
        push_back(a, capacity, length, 7);
        assert(length == 1);
        assert(a[0] == 7);
        assert(a[1] == -2);
        assert(a[2] == -3);
        push_back(a, capacity, length, 4);
        assert(length == 2);
        assert(a[0] == 7);
        assert(a[1] == 4);
        assert(a[2] == -3);
        push_back(a, capacity, length, 9);
        assert(length == 3);
        assert(a[0] == 7);
        assert(a[1] == 4);
        assert(a[2] == 9);
    } catch (...) { assert(false);  /* FAIL */ }

    std::cout << __func__ << ": all tests passing" << std::endl;
}

void test_pop_back() {
    // Given array = nullptr, capacity = 1, and length = 1
    // When I pop back
    // Then I should catch an exception
    // And length should be 1
    size_t length = 1;
    try {
        const size_t capacity = 1;  // lies
        pop_back(nullptr, capacity, length);
        assert(false);  // FAIL
    } catch (...) { assert(length == 1); }

    // Given an empty array (length = 0, capacity = 1)
    // When I pop back
    // Then I should catch an exception
    // And length should be 0
    length = 0;
    int* a = new int[1] {-1};  // sentinel value
    try {
        const size_t capacity = 1;
        pop_back(a, capacity, length);
        assert(false);  // FAIL
    } catch (...) {
        assert(length == 0);
        assert(a[0] == -1);
    }
    delete[] a;

    // Given an over-full array (length = 2, capacity = 1)
    // When I pop back
    // Then I should catch an exception
    // And length should be 2
    length = 2;
    a = new int[1] {-1};  // sentinel value
    try {
        int a[1] {1};
        const size_t capacity = 1;
        pop_back(a, capacity, length);
        assert(false);  // FAIL
    } catch (...) {
        assert(length == 2);
        assert(a[0] == -1);
    }
    delete[] a;

    // Given the array {7, 4, 9} (length = 3, capactiy = 3)
    // When I pop back
    // Then length should be 2
    // And the array should be {7, 4}
    // When I pop back
    // Then length should be 1
    // And the array should be {7}
    // When I pop back
    // Then length should be 0
    a = new int[3] {7, 4, 9};
    try {
        const size_t capacity = 3;
        size_t length = 3;
        pop_back(a, capacity, length);
        assert(length == 2);
        assert(a[0] == 7);
        assert(a[1] == 4);
        pop_back(a, capacity, length);
        assert(length == 1);
        assert(a[0] == 7);
        pop_back(a, capacity, length);
        assert(length == 0);
    } catch (...) {
        assert(false);  /* FAIL */
    }
    delete[] a;

    std::cout << __func__ << ": all tests passing" << std::endl;
}

int main() {
    test_push_back();
    test_pop_back();

    return 0;
}