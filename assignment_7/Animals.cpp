#include "includes.hpp"


void testAnimal(){
    std::vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Dog ("Jippi",10));
    animals.emplace_back(new Cat("Pusen",5));

    for (unsigned long long i = 0; i < animals.size(); i++)
    {
        std::cout << animals.at(i) -> toString() << std::endl;
    }
};



