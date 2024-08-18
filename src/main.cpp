#include <iostream>
#include <thread>
#include "../include/student_manager.h"

StudentManager manager;

void addStudentThread(int number, int note, const std::string& name, const std::string& surname) {
    Student newStudent(note, number, name, surname);
    manager.addStudent(newStudent);
    std::cout << "\nStudent added successfully." << std::endl;
}

void removeStudentThread(int number) {
    manager.removeStudent(number);
    std::cout << "\nStudent deleted successfully." << std::endl;
}

void searchStudentThread(int number) {
    Student* student = manager.findStudent(number);
    if (student) {
        std::cout << "\nStudent Name: " << student->getName() << std::endl;
        std::cout << "Student Surname: " << student->getSurname() << std::endl;
        std::cout << "Student Id: " << student->getnumber() << std::endl;
        std::cout << "Student Note: " << student->getNote() << std::endl;
    }
    else {
        std::cout << "\nStudent not found." << std::endl;
    }
}

int main() {
    int choice;

    while (true) {
        std::cout << "1- Add Student" << std::endl;
        std::cout << "2- Delete Student" << std::endl;
        std::cout << "3- Search Student" << std::endl;
        std::cout << "4- Load Students from File" << std::endl;
        std::cout << "5- Save Students to File" << std::endl;
        std::cout << "6- Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name, surname;
            int number, note;
            std::cout << "Enter name, surname, number, and note: ";
            std::cin >> name >> surname >> number >> note;
            std::thread(addStudentThread, number, note, name, surname).detach();
            break;
        }
        case 2: {
            int number;
            std::cout << "Enter student number to delete: ";
            std::cin >> number;
            std::thread(removeStudentThread, number).detach();
            break;
        }
        case 3: {
            int number;
            std::cout << "Enter student number to search: ";
            std::cin >> number;
            std::thread(searchStudentThread, number).detach();
            break;
        }
        case 4: {
            manager.loadFromFile("data/students_data.txt");
            std::cout << "Students loaded from file." << std::endl;
            break;
        }
        case 5: {
            manager.saveToFile("data/students_data.txt");
            std::cout << "Students saved to file." << std::endl;
            break;
        }
        case 6:
            std::cout << "Exiting program." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}
