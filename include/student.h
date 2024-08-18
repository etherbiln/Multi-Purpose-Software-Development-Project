#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person {
private:
    int note;

public:
    Student();
    Student(int note, int numberId, const std::string& name, const std::string& surname);
    ~Student();

    // GETTER
    int getNote() const { return note; }

    // SETTER
    void setNote(int note) { this->note = note; }
};

#endif // STUDENT_H
