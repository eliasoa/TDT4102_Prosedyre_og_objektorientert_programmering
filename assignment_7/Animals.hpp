#pragma once
#include "includes.hpp"

class Animal
{
protected:
    std::string name;
    int age;
public:
    /// @brief Constructor
    /// @param name string
    /// @param age int
    Animal(std::string name, int age): name{name}, age{age} {};
    
    /// @brief Destructor
    virtual ~Animal() {};

    virtual std::string toString() = 0;
};

class Cat : public Animal
{
public:
    /// @brief Constructor
    /// @param name string
    /// @param age int
    Cat( std::string name, int age ) :
    Animal{name,age}{}

    /// @brief 
    /// @return string
    std::string toString()override{
        std::string catName{name};
        std::string catAge = std::to_string(age);
        return "Cat: " + name + " " + catAge;
    };
};

class Dog : public Animal
{
public:
    /// @brief Constructor
    /// @param name string
    /// @param age int
    Dog(std::string name, int age) :
    Animal{name,age}{}

    /// @brief 
    /// @return string
    std::string toString()override{
        std::string dogName{name};
        std::string dogAge = std::to_string(age);
        return "Dog: " + name + " " + dogAge;
    };
};

// /// @brief Vector that holds different animals
// std::vector<unique_ptr<Animal>> animals;

/// @brief Function to test the Animal class and its Children
void testAnimal();
