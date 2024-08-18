#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    int numberId;
    std::string name;
    std::string surname;

public:
    Person();
    Person(int numberId, const std::string& name, const std::string& surname);
    virtual ~Person();

    // GETTERS
    int getnumber() const { return numberId; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }

    // SETTERS
    void setNumberId(int numberId) { this->numberId = numberId; }
    void setName(const std::string& name) { this->name = name; }
    void setSurname(const std::string& surname) { this->surname = surname; }
};

#endif // PERSON_H
