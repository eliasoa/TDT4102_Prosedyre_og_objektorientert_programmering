#pragma once
#include <string>
#include <iostream>
#include <list>

class Person
{
private:
    std::string firstName;
    std::string lastName;
public:
    Person(const std::string& firstName,const std::string& lastName): firstName{firstName}, lastName{lastName}{};
    std::string getFirstName() const {return firstName;};
    std::string getLastName() const {return lastName;};

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    bool operator<(const Person& p) const;
};

void insertOrdered(std::list<Person> &l, const Person& p);

void listProgram();