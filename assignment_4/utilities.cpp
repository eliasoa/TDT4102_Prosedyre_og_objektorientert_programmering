#include "utilities.h"


int incrementByValueNumTimes(int startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes){
        for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

void swapNumbers(int& a, int& b){
    int valueHolder = b;
    b = a;
    a = valueHolder;
}

void printStudent(Student student){
    cout << student.name 
    <<  " is studying " << student.studyProgram
    << " and is " << student.age << " years old."
    << endl;
}

bool isInProgram(Student student, string studyProgram){
    if (student.studyProgram == studyProgram) return true;
    else return false;    
}

string randomizeString(int numChars, char lowerBound, char upperBound){
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(static_cast<int>(lowerBound),static_cast<int>(upperBound));
    string ranodomString = "";
    for (int i = 0; i < numChars; i++)
    {
        int number = distribution(generator);
        ranodomString.push_back(static_cast<char>(number));
    }
    return ranodomString;
}

string readInputToString(const int length, char lowerBound, char upperBound){
    char userInput;
    string returnString = "";
    cout << "Write a charachter, then press Enter. Do this " << length << " times." << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> userInput;
        userInput = toupper(userInput);
               
        while (userInput < lowerBound)
        {
            cout << "Character is too low. Try again: ";
            cin >> userInput;
            userInput = toupper(userInput);
        }
        while (userInput > upperBound)
        {
            cout << "Character is too high. Try again: ";
            cin >> userInput;
            userInput = toupper(userInput);
        }
        returnString.push_back(userInput);
    }
    return returnString;
}

int countChar(const string& stringToCheck,const char& letter){
    int stringLength = stringToCheck.length();
    int counter = 0;
    for (int i = 0; i < stringLength; i++)
    {
        if (stringToCheck[i] == letter)
        {
            counter += 1;
        }
    }
    return counter;
}

void printVectorInt(const vector<int>& vectorToPrint){
    for (int i = 0; i < vectorToPrint.size(); i++)
    {
        cout << vectorToPrint.at(i) << endl;
    }
}