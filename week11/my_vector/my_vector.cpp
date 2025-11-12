#include <iostream>
#include <cassert>

class MyVector {
    int* array_;
    size_t capacity_;
    size_t size_;

 public:
    MyVector() : array_{nullptr}, capacity_{0}, size_{0} {}
    ~MyVector() { delete[] array_; }
    // break the rule of three and ignore copy {constructor, assignment}
    size_t capacity() const { return capacity_; }
    size_t size() const { return size_; }
    int at(size_t index) const { if (index >= size_) { throw std::out_of_range("at"); } return array_[index]; }
    int back() const { return at(size_ - 1); }

    // TODO(student): implement these 2 functions
    void resize(size_t new_capacity) {
        // 1. New
        int* new_array = new int[new_capacity];
        // 2. Copy
        size_t new_size = size_ <= new_capacity ? size_ : new_capacity;
        for (size_t i = 0; i < new_size; i++) {
            new_array[i] = array_[i];
        }
        // 3. Delete
        delete[] array_;
        // 4. Update
        array_ = new_array;
        capacity_ = new_capacity;
        size_ = new_size;
    }

    void push_back(int value) {
        if (array_ == nullptr) {
            array_ = new int[1] {value};
            capacity_ = 1;
            size_ = 1;
            return;
        }

        if (size_ == capacity_) {
            resize(2 * capacity_);
        }

        array_[size_] = value;
        size_++;
    }
};

int main() {
    MyVector vec;

    for (int i = 1; i <= 8675309; i++) {
        vec.push_back(i);
        assert(vec.back() == i);
        assert(vec.size() == static_cast<unsigned>(i));
    }

    assert(vec.capacity() == 16777216);
    assert(vec.size() == 8675309);
    for (int i = 1; i <= 8675309; i++) {
        assert(vec.at(i-1) == i);
    }

}
