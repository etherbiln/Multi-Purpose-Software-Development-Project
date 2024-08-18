#include "../include/student_manager.h"
#include <fstream>
#include <algorithm>

void StudentManager::addStudent(const Student& student) {
    std::lock_guard<std::mutex> lock(mtx);
    students.push_back(student);
}

void StudentManager::removeStudent(int numberId) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = std::remove_if(students.begin(), students.end(),
        [numberId](const Student& s) { return s.getnumber() == numberId; });
    students.erase(it, students.end());
}

Student* StudentManager::findStudent(int numberId) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = std::find_if(students.begin(), students.end(),
        [numberId](const Student& s) { return s.getnumber() == numberId; });
    return (it != students.end()) ? &(*it) : nullptr;
}

void StudentManager::loadFromFile(const std::string& filename) {
    std::lock_guard<std::mutex> lock(mtx);
    std::ifstream file(filename);
    if (file.is_open()) {
        int numberId, note;
        std::string name, surname;
        while (file >> numberId >> name >> surname >> note) {
            students.emplace_back(note, numberId, name, surname);
        }
        file.close();
    }
}

void StudentManager::saveToFile(const std::string& filename) {
    std::lock_guard<std::mutex> lock(mtx);
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.getnumber() << " " << student.getName() << " "
                << student.getSurname() << " " << student.getNote() << "\n";
        }
        file.close();
    }
}
