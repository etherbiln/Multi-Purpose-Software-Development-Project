#include "../include/person.h";
#include "../include/student.h";

#include <iostream>

Person::Person() : numberId(0), name("null"), surname("null") {}
Person::Person(int numberId, std::string name, std::string surname)
{
	this->numberId = numberId;
	this->name = name;
	this->surname = surname;
}
Person::~Person()
{
	std::cout << "\nPerson destructor is running! \n";
}


Person getReturnPerson(Person person) {
	return person;
}

Student::Student(int note, int numberId, std::string name, std::string surname) {
	this->note = note;
	this->numberId = numberId;
	this->name = name;
	this->surname = surname;
}
Student::Student() {
	note = 0;
	numberId = 0;
	name = "null";
	surname = "null";
}
Student::~Student() {
	std::cout << "\nStudent destructor is running! \n";
}



Student getReturnStudent(Student student) {
	return student;
}
int getNoteInt(Student student) { return student.getNote(); }