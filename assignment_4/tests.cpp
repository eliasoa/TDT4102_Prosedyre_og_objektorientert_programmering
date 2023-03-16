#include "tests.h"
#include "utilities.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testCallByReference(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    cout << "Before incrementByValueNumTimesRef()\nv0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations << endl;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "After\nv0: " << v0 << endl;
}

void testString(){
    string grades = randomizeString(8,'A','F');
    int numA = countChar(grades,'A');
    int numB = countChar(grades,'B');
    int numC = countChar(grades,'C');
    int numD = countChar(grades,'D');
    int numE = countChar(grades,'E');
    int numF = countChar(grades,'F');
    vector<int> gradeCount{numA, numB, numC, numD, numE, numF};
    cout << grades << endl;
    // printVectorInt(gradeCount);
    float averageGrade = (5*numA + 4*numB + 3*numC + 2*numE + 1*numF)/reduce(gradeCount.begin(),gradeCount.end());
    cout << "The average grade is " << averageGrade << endl;
    
}