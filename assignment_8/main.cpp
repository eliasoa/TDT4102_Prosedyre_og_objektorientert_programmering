#include "includes.hpp"

int main() {
    // Problem 1    
    // createFibonacci();

    // Problem 2
    // Matrix myIdentityMatrix(5);
    // int row{2};
    // int column{4};
    // Matrix aMatrix(row,column);
    // Matrix bMatrix{aMatrix};
    // Matrix cMatrix{aMatrix};
    // aMatrix.fillMatrix();
    // bMatrix.fillMatrix();
    // std::cout << myIdentityMatrix << std::endl;
    // std::cout << aMatrix << std::endl;
    
    // Problem 3
    // dummyTest();

    // Problem 4
    // Matrix copyOfaMatrix = aMatrix;

    // std::cout << "aMatrix is first:\n" << aMatrix << std::endl;
    // std::cout << "Copy of aMatrix is first:\n" <<copyOfaMatrix << std::endl;
    
    // copyOfaMatrix.fillMatrix();

    // std::cout << "aMatrix:\n" << aMatrix << std::endl;
    // std::cout << "Copy of aMatrix:\n" <<copyOfaMatrix << std::endl;

    // Problem 5
    // myIdentityMatrix += myIdentityMatrix;
    // std::cout << aMatrix << std::endl;
    // aMatrix += aMatrix;
    // std::cout << aMatrix << std::endl;

    Matrix A {2,2};
    Matrix B {2,2};
    Matrix C {2,2};

    A.set(0,0,1);
    A.set(0,1,2);
    A.set(1,0,3);
    A.set(1,1,4);
    
    B.set(0,0,4);
    B.set(0,1,3);
    B.set(1,0,2);
    B.set(1,1,1);

    C.set(0,0,1);
    C.set(0,1,3);
    C.set(1,0,1.5);
    C.set(1,1,2);

    std::cout << "A:\n" << A << std::endl;
    std::cout << "B:\n" << B << std::endl;
    std::cout << "C:\n" << C << std::endl;

    A += B+C;
    std::cout << "The new A:\n" << A << std::endl;
    std::cout << "B:\n" << B << std::endl;
    std::cout << "C:\n" << C << std::endl;
    return 0;
}

/* Teorispørsmål
3a)
See comments in Dummy.cpp
Output
a: 4
b: 4
c: 4
a: 5
b: 5
c: 5
The output matches my guess. Since we didnt define a "=" operator for the Dummy class, the default one is used instead.
This means that when we write *numb.c = 5, this means that the memory address c poitns to gets altered to 5.
Since we also used "=" to initialize b and c, from a, this means that they all point to the same address.
3b)
Output:
a: 4
b: 4
c: 4
a: 5
b: 3
c: 5
and then the program crashes.
This is more correct. As b now is created by the Copy Constructor made, but c still copies a's address.
*/