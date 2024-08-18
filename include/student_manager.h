#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "student.h"
#include <vector>
#include <mutex>

class StudentManager {
private:
    std::vector<Student> students;
    std::mutex mtx;

public:
    void addStudent(const Student& student);
    void removeStudent(int numberId);
    Student* findStudent(int numberId);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
};

#endif // STUDENT_MANAGER_H
