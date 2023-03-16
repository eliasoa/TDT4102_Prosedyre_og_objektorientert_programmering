#include "mastermind.h"
#include "utilities.h"

void playMastermind(){
    constexpr int size = 4;
    constexpr int letters = 6;
    char lowerBound = 'A';
    char upperBound = 'A'+ (letters-1);
    string code = randomizeString(4,lowerBound,upperBound);
    string guess;

    int correctPosition = 0;
    int correctChars = 0;
    int numberOfGuesses = 3;
    cout << code << endl;

    while (correctPosition < size)
    {
        guess = readInputToString(4,lowerBound,upperBound);
        correctPosition = checkCharactersAndPosition(code,guess);
        correctChars = checkCharacters(code,guess);
        cout << "Number of correct characters: " << correctChars << "\n" <<
        "Characters in correct position: " << correctPosition << endl;
        numberOfGuesses -= 1;
        if (numberOfGuesses<1)
        {
            break;
        }
    }
    if (correctPosition==size)
    {
        cout << "You are the mastermind ;)" << endl;
    }
    else
    {
        cout << "You are not the mastermind :(" << endl;
    }
        
};

int checkCharactersAndPosition(const string& code, const string& guess){
    int correctPosition = 0;
    for (int i = 0; i < code.size(); i++)
    {
        if (code[i]==guess[i])
        {
            correctPosition += 1;
        }
    }
    return correctPosition;
} 

int checkCharacters(const string& code, const string& guess){
    int correctCharacters = 0;
    vector<char> allreadyChecked;
    for (int i = 0; i < code.length(); i++)
    {
        char currentChar = guess[i];
        if(find(allreadyChecked.begin(), allreadyChecked.end(), currentChar)!=allreadyChecked.end()){ // from: https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector
        // Found the item, do nothing
        }
        else
        {
            int num = countChar(code,currentChar);
            correctCharacters += num;
        }
        allreadyChecked.push_back(currentChar);
    }
    return correctCharacters;
}