#include "../include/person.h"
#include <iostream>

Person::Person() : numberId(0), name("null"), surname("null") {}

Person::Person(int numberId, const std::string& name, const std::string& surname)
    : numberId(numberId), name(name), surname(surname) {}

Person::~Person() {
    std::cout << "\nPerson destructor is running! \n";
}
