#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

#include "person.h";
#include "student.h";

void getShowPerson(Person person) {
	std::printf("--- Person Data ---\n\n");
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



int main() {
	list<Student> listStudent;
	Student student(1,123,"Yakup","Bilen");

	listStudent.push_back(student);

	cout << listStudent.empty();

	return 0;
}