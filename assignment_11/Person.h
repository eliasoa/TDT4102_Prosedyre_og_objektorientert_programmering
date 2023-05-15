#pragma once
#include <string>
#include <iostream>

class Person
{
private:
    std::string firstName;
    std::string lastName;
public:
    Person(std::string firstName,std::string lastName): firstName{firstName}, lastName{lastName}{};
    std::string getFirstName() const {return firstName;};
    std::string getLastName() const {return lastName;};

    friend std::ostream& operator<<(std::ostream& os, Person p);
};

std::ostream& operator<<(std::ostream& os, Person p){
    os << p.firstName << " " << p.lastName;
    return os;
}