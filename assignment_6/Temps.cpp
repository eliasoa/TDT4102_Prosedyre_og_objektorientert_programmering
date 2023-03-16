#include "includes.hpp"


istream& operator>>(istream& is, Temps& t){
    return is >> t.max >> t.min;
}

vector<Temps> readTemps(const string& dataFile){
    vector<Temps> tempVector;
    string line{""};

    std::filesystem::path temperatureFile{dataFile};
    std::ifstream ist{temperatureFile};

    for (Temps t; ist >> t;)
    {
        tempVector.push_back(t);
    }
    
    return tempVector;
}