#pragma once
#include <iostream>
#include <utility>
class Dummy {
public:
    int *num;
    Dummy() {
        num = new int{0};
    }

    Dummy(const Dummy &old_dummy);

    Dummy operator=(Dummy rhs){
    std::swap(num,rhs.num);
    return *this;
    }; 

    ~Dummy() {
        delete num;
    }
};
void dummyTest();