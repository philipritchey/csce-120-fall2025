#include <iostream>
#include <string>

#include <cassert>

using std::cout, std::endl, std::ostream, std::string;

class Student {
    string* name_;

 public:
    explicit Student(const string& name) : name_{new string(name)} {}
    ~Student() { delete name_; }
    Student(const Student& other) : name_{other.name_} {}
    Student& operator=(const Student& other) {
        *name_ = *other.name_;
        return *this;
    }
    const string& name() const { return *name_; }
};

ostream& operator<<(ostream& os, const Student& student) {
    return os << "Student: " << student.name();
}

void test_copy_assignment() {
    Student a("Alice");
    Student b("Bob");

    a = b;

    // names should be the same
    assert(a.name() == b.name());

    // names should be "Bob"
    assert(a.name() == "Bob");

    // but pointers should be different
    assert(&a.name() != &b.name());
}

int main() {
    test_copy_assignment();

    Student a("Alice");
    Student b("Bob");

    b = a;

    cout << a << endl;
    cout << b << endl;

    return 0;
}
