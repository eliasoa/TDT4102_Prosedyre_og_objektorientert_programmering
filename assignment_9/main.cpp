#include <iostream>
#include "Car.h"
#include "Person.h"
#include "Meeting.h"

int main() {
    //Denne testen er tatt fra LF, orket ikke skrive selv ;)
    std::unique_ptr<Car> fullCar {new Car{0}};
	std::unique_ptr<Car> car {new Car{5}};

	std::shared_ptr<Person> p1 { new Person{"p1", "p1@ntnu.no"}};
	std::shared_ptr<Person> p2 { new Person{"p2", "p2@ntnu.no"}};
	std::shared_ptr<Person> p3 { new Person{"p3", "p3@ntnu.no", std::move(fullCar)}};
	std::shared_ptr<Person> p4 { new Person{"p4", "p4@ntnu.no", std::move(car)}};
	std::shared_ptr<Person> p5 { new Person{"p5", "p5@ntnu.no", std::make_unique<Car>(5)}};
	std::shared_ptr<Person> p6 { new Person{"p6", "p6@ntnu.no"}};

	Meeting trh1{1, 9, 14, Campus::trd, "C++", p1};
	trh1.addParticipant(p3);

	Meeting gjo{1, 9, 14, Campus::gjo, "Fusion", p2};
	gjo.addParticipant(p4);

	Meeting trh2{1, 9, 14, Campus::trd, "Faculty naming", p5};
	trh2.addParticipant(p6);
	trh2.addParticipant(p4);

	std::cout << "All meetings:" << std::endl << trh1 << std::endl << gjo << std::endl << trh2 << std::endl;

	std::cout << "Persons at meetings concurrent with the " << trh1.getSubject() << "-meeting:\n";
	for (auto &p : trh1.findPotentialCoDriving(trh2)) {
		std::cout << *p << std::endl;
	}   
    return 0;
}