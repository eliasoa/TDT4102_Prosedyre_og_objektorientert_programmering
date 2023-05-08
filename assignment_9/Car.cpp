#include "Car.h"


bool Car::hasFreeSeats() const{
    if (freeSeats){
        return true;
    }
    else{
        return false;
    }
};


void Car::reserveFreeSeat(){
    freeSeats -= 1;
};

// int Car::getFreeSeats(){
//     return freeSeats;
// }