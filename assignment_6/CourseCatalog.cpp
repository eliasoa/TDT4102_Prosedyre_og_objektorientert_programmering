#include "includes.hpp"


CourseCatalog::CourseCatalog(/* args */)
{
}

void CourseCatalog::addCourse(const string& courseCode, const string& courseName){
    if (CourseCatalog::courseCatalog.count(courseCode))
    {
        cout << "The course already is in the course catalog" << endl;
    }
    else
    {
        CourseCatalog::courseCatalog.insert({courseCode,courseName});
        cout << "Added the course " << CourseCatalog::courseCatalog.at(courseCode) << " with course code " << courseCode << endl;
    }
    
    
    
}

void CourseCatalog::removeCourse(const string& courseCode){
    if (!CourseCatalog::courseCatalog.count(courseCode))
    {
        cout << "The course is not in the course catalog" << endl;
    }
    else
    {
        cout << "Removed the course " << CourseCatalog::courseCatalog.at(courseCode) << " with course code " << courseCode << endl;
        CourseCatalog::courseCatalog.erase(courseCode);
    }    

}

string CourseCatalog::getCourse(const string& courseCode){
    return CourseCatalog::courseCatalog.at(courseCode);
} 

ostream& operator <<(ostream& os, const CourseCatalog& c){
    for (const auto& [courseCode, courseName]:c.courseCatalog)
    {
        os << courseCode << ":\t" << courseName << endl;
    }
    return os;
}


void CourseCatalog::exportCourseCatalog(const string& dataFile){
    std::filesystem::path fileName(dataFile + ".csv");
    std::ofstream ost{fileName};

    for (const auto& [courseCode, courseName]:courseCatalog)
    {
        ost << courseCode << "," << courseName << endl;
    }
}

void CourseCatalog::loadCourseCatalog(const string& dataFile){
    std::ifstream ist {dataFile};
    string line{""};
    courseCatalog.clear();
    while (std::getline(ist,line))
    {
        std::stringstream ss(line);
        string courseCode;
        string courseName;
        
        getline(ss,courseCode,',');
        getline(ss,courseName,',');
        courseCatalog.insert({courseCode,courseName});
    }
}