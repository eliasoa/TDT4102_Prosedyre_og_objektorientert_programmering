#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>

/// @brief Replaces elements equal to old with replace in vec
/// @param vec Vector reference
/// @param old String to replace
/// @param replace String replacement
void replace(std::vector<std::string> &vec, std::string old, std::string replace);

/// @brief Replaces elements equal to old with replace in set
/// @param set Set reference
/// @param old String to replace
/// @param replace String replacement
void replace(std::set<std::string> &set, std::string old, std::string replace);

/// @brief Run problem 1
void problem1();