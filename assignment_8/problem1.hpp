#pragma once


/// @brief Funksjon som skal regne ut length antall tall i Fibonacci-tallfølgen
/// @param result pointer to array to store Fibonacci-numbers
/// @param length number of Fibonacci-numbers
void fillInFibonacciNumbers(int* result, int length);



/// @brief Function that prints "length" elements from the arr
/// @param arr pointer to array
/// @param length int
void printArray(int* arr, int length);


/// @brief Function that prompts the user for the length of the fibonacci-array, fills it up and prints it out
void createFibonacci();