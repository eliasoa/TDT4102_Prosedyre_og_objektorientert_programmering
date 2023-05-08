#pragma once

#include <string>
#include <memory>
#include "Car.h"
#include <iostream>

class Person
{
private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> car;
public:
    Person(const std::string& name, const std::string& email, std::unique_ptr<Car> car = nullptr);

    std::string getName() const;  

    std::string getEmail() const;  

    void setEmail(const std::string& email);

    bool hasAvailableSeat();
};
std::ostream &operator<<( std::ostream &output, const Person& p);