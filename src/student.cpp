#include "../include/student.h"
#include <iostream> // Bu satırı ekleyin

Student::Student() : Person(), note(0) {}

Student::Student(int note, int numberId, const std::string& name, const std::string& surname)
    : Person(numberId, name, surname), note(note) {}

Student::~Student() {
    std::cout << "\nStudent destructor is running! \n";
}
