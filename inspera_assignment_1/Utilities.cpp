#include "Utilities.h"

string toGreek(string sentence)
{
    // BEGIN: 2a
    string newSentence;
    for (auto& letter:sentence)
    {
        if(isspace(letter)){
            newSentence += letter;
        }
        else{
            letter += 2;
            newSentence += letter;  
        }
    }
    return newSentence;
    // END: 2a
}

vector<vector<string>> loadSvada()
{
    // BEGIN: 2b

    // Write your answer to assignment 2b here, between the // BEGIN: 2b
    // and // END: 2b comments. Remove the code that is already there.

    return vector<vector<string>>{};

    // END: 2b
}

string svadaGenerator(vector<vector<string>> svadaVec)
{
    // BEGIN: 2c1

    // Write your answer to assignment 2c1 here, between the // BEGIN: 2c1
    // and // END: 2c1 comments. Remove the code that is already there.

    (void)svadaVec;
    return "";
    
    // END: 2c1
}