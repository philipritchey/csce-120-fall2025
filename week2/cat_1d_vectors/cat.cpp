#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int uin;
    float grade;
};

int main() {
    // create a vector of Students
    std::vector<Student> students;

    // add students to the vector
    students.push_back({"Alice", 123004567, 84});
    students.push_back({"Bob", 867005309, 72});
    students.push_back({"Carol", 314001592, 91});

    // access the first student in the vector
    // note: the type of the LHS is Student&, which means "reference to Student"
    //       this means `first` refers to the Student at the `front` of `students`
    //       `first` and `students.front()` are the same object (are identical)
    Student& first = students.front();  // equiv. students.at(0)

    // access the last student in the vector
    // note: the type of the LHS is Student, which means "value of Student"
    //       this means `last` is a Student whose value is the same as the Student at the `back` of `students`
    //       `last` and `student.back()` are two different objects that have the same value (are equal, but not identical)
    Student last = students.back(); // equiv. students.at(students.size()-1)

    // access a student in the middle of the vector
    // note: the type of the LHS is a value, not a reference.
    //       so, `middle` is a copy of `student.at(1)`
    Student middle = students.at(1);

    // change the first student's grade
    first.grade = 86.75309;

    // change the middle student's grade?
    // no.  since `middle` is a copy of the middle student, this does NOT change the middle student's grade
    // it only changes `middle`s grade, but `middle` is only a copy of the middle student
    middle.grade = 99.9;

    // change the last student's grade
    // since `students.back()` returns a reference to the last student, this will change the last student's grade
    students.back().grade = 94.5;

    // print names and grades
    // this is a range-based for loop, which lets us traverse an iterable container nicely
    // for (Type value : container) -> "for each value (which has type Type) in container (which contains Type values)"
    // "for each Student student in students"
    for (Student student : students) {
        // within the loop body, `student` is the value of the Student we are currently processing in our traversal
        // print the name and grade of the Student
        std::cout << student.name << " " << student.grade << std::endl;
    }

    std::cout << "-----" << std::endl;

    // the range-based for loop is equivalent to a standard for loop where we explicitly access each element:
    for (size_t index = 0; index < students.size(); ++index) {
        Student student = students.at(index);
        std::cout << student.name << " " << student.grade << std::endl;
    }

    std::cout << "-----" << std::endl;

    // "anonymize" the students?
    for (Student student : students) {
        student.name = "anonymous";
        std::cout << student.name << " " << student.grade << std::endl;
    }

    // nope. see:
    for (Student student : students) {
        std::cout << student.name << " " << student.grade << std::endl;
    }

    std::cout << "-----" << std::endl;

    // the above traversals use values: Student student
    // this one uses references: Student& student
    // this saves time because the Student values don't get copied into new objects
    // this also means that we have access to the actual students in the container
    // so, if we modify `student` we are actually modifying an element of the container, not just a copy
    for (Student& student : students) {
        student.name = "student" + std::to_string(student.uin % 10000);
        std::cout << student.name << " " << student.grade << std::endl;
    }

    for (Student& student : students) {
        std::cout << student.name << " " << student.grade << std::endl;
    }

    std::cout << "-----" << std::endl;

    // if we only need to read the data (not modify it)
    // then we can use `const` to let the compiler know the values should not be changed
    // coupling const with access-by-reference, we get fast read-only access
    for (const Student& student : students) {
        // student.name = "anonymous";  // this line is now illegal, the compiler won't accept it
        std::cout << student.name << " " << student.grade << std::endl;
    }

    return 0;
    }