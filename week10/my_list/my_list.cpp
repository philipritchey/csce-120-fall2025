#include <cassert>
#include <stdexcept>

class MyList {
    size_t capacity_;
    size_t size_;
    int* array_;

 public:
    MyList(size_t the_capacity) : capacity_{the_capacity}, size_{0}, array_{new int[the_capacity]} {
        if (the_capacity == 0) {
            delete[] array_;
            throw std::invalid_argument("capacity cannot be 0");
        }
    }
    ~MyList() {
        delete[] array_;
    }
    size_t capacity() const { return capacity_; }
    size_t size() const { return size_; }
    bool empty() const { return size() == 0; }
    void push_back(int value) {
        if (size_ == capacity_) {
            throw std::out_of_range("list is full");
        }
        array_[size_] = value;
        size_++;
    }
    int& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("out of bounds");
        }
        return array_[index];
    }
    int& front() { return array_[0]; }
    // int const& front() const { return array_[0]; }
    int& back() { return array_[size_ - 1]; }
    void pop_back() {
        if (empty()) {
            throw std::out_of_range("empty list");
        }
        size_--;
    }


};

int main() {
    // create a list with initial capacity
    MyList list(20);

    assert(list.capacity() == 20);
    assert(list.size() == 0);
    assert(list.empty());

    list.push_back(1);

    assert(list.capacity() == 20);
    assert(list.size() == 1);
    assert(!list.empty());
    assert(list.at(0) == 1);
    assert(list.front() == 1);
    assert(list.back() == 1);

    for (int i = 1; i < 10; i++) {
        list.push_back(i);
    }

    assert(list.capacity() == 20);
    assert(list.size() == 10);
    assert(!list.empty());
    assert(list.at(7) == 7);
    assert(list.front() == 1);
    assert(list.back() == 9);

    list.pop_back();

    assert(list.capacity() == 20);
    assert(list.size() == 9);
    assert(!list.empty());
    assert(list.at(7) == 7);
    assert(list.front() == 1);
    assert(list.back() == 8);

    try {
        list.at(20); // out of bounds access
        // bad
        assert(false);
    } catch (std::out_of_range const& err) {
        // good
    }

    try {
        list.at(9); // uninitialized/stale access
        // bad
        assert(false);
    } catch (std::out_of_range const& err) {
        // good
    }

    for (int i = 0; i < 9; i++) {
        list.pop_back();
    }

    assert(list.capacity() == 20);
    assert(list.size() == 0);
    assert(list.empty());

    try {
        list.at(0);
        // bad
        assert(false);
    } catch (std::out_of_range const& err) {
        // good
    }

    try {
        list.pop_back();
        // bad
        assert(false);
    } catch (std::out_of_range const& err) {
        // good
    }

    for (int i = 0; i < 20; i++) {
        list.push_back(i);
    }

    assert(list.size() == 20);
    assert(list.front() == 0);
    assert(list.back() == 19);

    try {
        list.push_back(20);
        // bad
        assert(false);
    } catch (std::out_of_range const& err) {
        // good
    }

    list.front() = 2;
    assert(list.front() == 2);

    list.back() = 2;
    assert(list.back() == 2);

    list.at(7) = 2;
    assert(list.at(7) == 2);

    try {
        MyList list(-1);
        assert(false);
    } catch (const std::bad_array_new_length& err) { /* good */}

    try {
        MyList list(0);
        assert(false);
    } catch (const std::invalid_argument& err) { /* good */}

    return 0;
}