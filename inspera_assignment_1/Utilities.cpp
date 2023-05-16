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
    
    vector<string> svada;
    vector<vector<string>> sortedSvada;

    string filename = "SvadaWords.txt";
    ifstream ifs(filename);
    if (!ifs){
        error("Couldn't open file: ", filename);
    }
    string line;
    while (getline(ifs, line)){
        if (line == "||"){
            sortedSvada.push_back(svada);
            svada.clear();
        }
        else{
            svada.push_back(line);
        }
    }
    sortedSvada.push_back(svada);
    ifs.close();
    
    return sortedSvada;

    // END: 2b
}

string svadaGenerator(vector<vector<string>> svadaVec)
{
    // BEGIN: 2c1
    string text;
    
    for (auto svadaGroup:svadaVec){
        int randNum {rand() % static_cast<int>(svadaGroup.size())};
        text += svadaGroup.at(randNum) + " ";
    }
    return text;
    // END: 2c1
}