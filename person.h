#ifndef PERSON_H
#define PERSON_H
#include <string>

#include <iostream>

// taban sýnýf
class Person {
protected:
	int numberId;
	std::string name;
	std::string surname;
public:
	Person();
	Person(int numberId, std::string name, std::string surname);
	~Person();

	// GET
	int getnumber() { return numberId; }
	std::string getName() { return name; }
	std::string getSurname() { return surname; }
	//SET
	void setNumberId(int numberId) { this->numberId = numberId; }
	void setName(std::string name) { this->name = name; }
	void setSurname(std::string surname) { this->surname = surname; }
	//--//
	Person getReturnPerson(Person person) {}
	void getShowPerson(Person person){}
};


#endif