#pragma once
#include "includes.hpp"

struct Temps
{
    float min;
    float max;
};

/// @brief Function that overloads >> operator s.t. 
/// @param is 
/// @param t 
/// @return 
istream& operator>>(istream& is, Temps& t);

/// @brief Function that returns a vector of temps from a file
/// @param dataFile 
/// @return vector of Temps
vector<Temps> readTemps(const string& dataFile);