#include <iostream>
#include <thread>
#include <stdio.h>
#include <list>

using namespace std;

#include "../include/person.h";
#include "../include/student.h";

void getShowPerson(Person person) {
    std::printf("\n--- Person Data ---\n\n");
    std::cout << "Person Name: " << person.getName() << std::endl;
    std::cout << "Person Surname: " << person.getSurname() << std::endl;
    std::cout << "Person Id: " << person.getnumber() << std::endl;
}
void getShowStudent(Student student) {
    printf("\n--- Student Data ---\n\n");
    std::cout << "Student Name: " << student.getName() << std::endl;
    std::cout << "Student Surname: " << student.getSurname() << std::endl;
    std::cout << "Student Id: " << student.getnumber() << std::endl;
    std::cout << "Student Note: " << student.getNote() << std::endl;
}

list<Student> listStudent;
Student student;

void addStudentLogic(int number, int note,string name, string surname) {
    Student newStudent(note, number, name, surname);
    listStudent.push_back(newStudent);
    std::cout << "\nStudent added successfully." << std::endl;
}

void deleteStudentLogic(int number) {
    for (auto it = listStudent.begin(); it != listStudent.end(); ++it) {
        if (it->getnumber() == number) {
            listStudent.erase(it);
            std::cout << "\nStudent deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "\nStudent not found." << std::endl;
}

void searchStudentLogic(int number) {
    for (auto& student : listStudent) {
        if (student.getnumber() == number) {
            getShowStudent(student);
            return;
        }
    }
    std::cout << "\nStudent not found." << std::endl;
}


int main() {
    int choice;

    while (true) {
        std::cout << "1- Student add" << std::endl;
        std::cout << "2- Student delete" << std::endl;
        std::cout << "3- Student search" << std::endl;
        std::cout << "4- Exit" << std::endl;
        std::cout << "Enter data: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            string name, surname;
            int number, note;
            std::cout << "\nEnter name, surname, number, and note: ";
            std::cin >> name >> surname >> number >> note;
            std::thread(addStudentLogic, number, note, name, surname).detach();
            break;
        }
        case 2: {
            int number;
            std::cout << "\nEnter student number to delete: ";
            std::cin >> number;
            std::thread(deleteStudentLogic, number).detach();
            break;
        }
        case 3: {
            int number;
            std::cout << "\nEnter student number to search: ";
            std::cin >> number;
            std::thread(searchStudentLogic, number).detach();
            break;
        }
        case 4:
            std::cout << "\nExiting program." << std::endl;
            return 0;
        default:
            std::cout << "\nInvalid choice. Please try again." << std::endl;
        }

    }
    return 0;
}
