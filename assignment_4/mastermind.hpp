#pragma once
#include "std_lib_facilities.h"

/// @brief Function that starts Mastermind
void playMastermind();

/// @brief Function that returns how many correct characters are in the correct position
/// @param code the code the player must try to guess 
/// @param guess the users guess
/// @return int
int checkCharactersAndPosition(const string& code, const string& guess);

/// @brief Function that returns how many correct characters are in the users guess, regardless of position
/// @param code the code the player must try to guess
/// @param guess the users guess
/// @return int
int checkCharacters(const string& code, const string& guess);