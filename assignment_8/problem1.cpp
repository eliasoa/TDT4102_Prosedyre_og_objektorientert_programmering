#include "includes.hpp"

void fillInFibonacciNumbers(int* result, int length){
    // Stod på Piazza
    if (length < 1)
    {
        // Do nothing
        return;
    }
    result[0] = 0;
    if (length > 1)
    {
        result[1] = 1;
    }

    for (int i = 2; i < length; i++)
    {
        result[i] = result[i-1] + result[i-2];
    }
}

void printArray(int* arr, int length){
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

void createFibonacci(){
    int length{0};
    std::cout << "What lenght you want for your fibonacci-array?" << std::endl;
    std::cin >> length;
    // Allocates memory for the results array?
    int* results = new int [static_cast<unsigned long long>(length)];
    fillInFibonacciNumbers(results, length);
    printArray(results,length);
    delete[] results;
    results = nullptr;
}