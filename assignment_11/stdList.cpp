#include "stdList.h"

std::ostream& operator<<(std::ostream& os, const Person& p){
    os << p.getLastName() << ", " << p.firstName;
    return os;
}
bool Person::operator <(const Person& p) const {
    return (lastName + lastName) < (p.lastName + p.firstName);
}


void insertOrdered(std::list<Person> &l, const Person& p){
    for (auto it = l.begin(); it!=l.end(); it++){
        if (p < *it){
            l.insert(it,p);
            return;
        }
    }
    l.push_back(p);
}

void listProgram(){
     std::cout << "std::list:" << '\n';

    std::list<Person> people;
    insertOrdered(people, Person("MF", "Doom")); //RIP ALL CAPS
    insertOrdered(people, Person("Oral", "Bee"));
    insertOrdered(people, Person("Mr", "PimpLotion"));
    insertOrdered(people, Person("Biggie", "Smalls"));
    insertOrdered(people, Person("Snoop", "Dogg"));

    for (const auto& p : people){
        std::cout << p << '\n';
    }
    // Alternativt <algorithm>
    // std::copy(people.begin(), people.end(), std::ostream_iterator<Person>(std::cout, "\n"));

    std::cout << '\n';
}