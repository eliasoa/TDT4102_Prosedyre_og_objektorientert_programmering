#pragma once
#include "includes.hpp"


/// @brief Function that lets the user write strings to a file
void userWriteToFile();

/// @brief Function that reads from a text file, creates a new files, writes the same as in the old text file, only with line numbers
void readFromFileAndCreatNewOneWithLineNumbers(const string& fileToCopy);

/// @brief Function that counts the number of apperances of each letter in the english alfabet in a file
/// @param fileToCheck 
void characterStatisticsOfFile(const string& fileToCheck);