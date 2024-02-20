#ifndef STUDENT_H
#define STUDENT_H


#include "person.h";


class Student :public Person {
private:
	int note;
public:
	Student();
	Student(int note, int numberId, std::string name, std::string surname);
	~Student();
	
	//GET
	int getNoteFunc(Student student) {};
	int getNote() { return note; }
	
	//SET
	void setNote(int note) { this->note = note; }

	//--//
	Student getReturnStudent(Student student) {}
	void getShowStudent(Student student) {}
};

#endif