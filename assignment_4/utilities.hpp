#pragma once
#include "std_lib_facilities.h"

/// @brief Function that increments startValue by incremet numTimes
/// @param startValue int
/// @param increment int
/// @param numTimes int
/// @return startValue
int incrementByValueNumTimes(int startValue, int increment, int numTimes);

/// @brief Function that increments startValue by incremet numTimes, but takes a reference as the argument
/// @param startValue 
/// @param increment 
/// @param numTimes 
void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);

/// @brief Function that swaps the value of two numbers
/// @param a int
/// @param b int
void swapNumbers(int& a, int& b);

/// @brief Struct containing info about Student
struct Student
{
    string name;
    string studyProgram;
    int age;
};

/// @brief Function that prints the info in the Student struct in a "nice" way
/// @param student Struct of type Student
void printStudent(Student student);

/// @brief Function that checks if a student is enrolled in a study programme
/// @param student Struct of type Student
/// @param studyProgram String with study programme
/// @return true or false
bool isInProgram(Student student, string studyProgram);

/// @brief Function that returns a string of length numChars and contains char in a given interval
/// @param numChars length of string
/// @param lowerBound lower bound of char, eg 'A'
/// @param upperBound upper bound of char, eg 'F'
/// @return string
string randomizeString(int numChars, char lowerBound, char upperBound);

/// @brief Function that takes user input (char) and returns a string, valid 
/// @param length number of inputs from user
/// @param lowerBound lower bound of char, eg 'A'
/// @param upperBound upper bound of char, eg 'F'
/// @return string
string readInputToString(int length, char lowerBound, char upperBound);

/// @brief Function that checks a string for the number of a specified letter
/// @param stringToCheck string to check
/// @param letter which letter to check for
/// @return int
int countChar(const string& stringToCheck,const char& letter);

/// @brief Function that prinst the elements of a vector with ints
/// @param vectorToPrint vector whos elements is to be printed
void printVectorInt(const vector<int>& vectorToPrint);