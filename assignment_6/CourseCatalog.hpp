#pragma once
#include "includes.hpp"

class CourseCatalog
{
private:
    map<string, string> courseCatalog;
public:
    /// @brief Constructor
    CourseCatalog(/* args */);

    /// @brief Function that adds a course to the courseCatalog map
    /// @param courseCode e.g. TDT4102
    /// @param courseName e.g. Prosedyre og objektorientert programmering
    void addCourse(const string& courseCode, const string& courseName);

    /// @brief Function that removes a course from the courseCatalog map
    /// @param courseCode e.g. TDT4102
    void removeCourse(const string& courseCode);

    /// @brief Function that finds the course name by using the course code
    /// @param courseCode e.g. TDT4102 
    /// @return string e.g. Prosedyre og objektorientert programmering
    string getCourse(const string& courseCode);

    /// @brief overloading of the << operator
    /// @param os 
    /// @param c 
    /// @return 
    friend ostream& operator<<(ostream& os, const CourseCatalog& c);

    /// @brief Function that exports the course catalog to a external csv
    /// @param dataFile name of data file, will be a .csv filr
    void exportCourseCatalog(const string& dataFile);

    /// @brief Function that imports a course catalog 
    /// @param dataFile name of file to load, with file extension, has to be .csv
    void loadCourseCatalog(const string& dataFile);
};