#include "Person.h"

Person::Person(const std::string& name, const std::string& email, std::unique_ptr<Car> car) : name{name}, 
                                                                                            email{email}, 
                                                                                            car{std::move(car)} 
                                                                                            {};

std::string Person::getName() const{
    return name;
}

std::string Person::getEmail() const{
    return email;
}

void Person::setEmail(const std::string& email){
    this -> email = email;
}

bool Person::hasAvailableSeat(){
    if (car){
        if (car->hasFreeSeats()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

std::ostream &operator<<( std::ostream &output, const Person& p){
    return output << p.getName() << " (" << p.getEmail() << ")" << std::endl;
};

