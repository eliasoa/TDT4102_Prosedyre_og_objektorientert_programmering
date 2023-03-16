#include "includes.hpp"

const map<string, string> capitalsMap {
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}
};
string getCapital(const string& country) {
    return capitalsMap.at(country);
}

int main() {

    // Problem 1b
    // readFromFileAndCreatNewOneWithLineNumbers("TheTragedyofDarthPlagueistheWise.txt");

    // Problem 2a
    characterStatisticsOfFile("grunnlov.txt");

    // Problem 2b
    std::cout << "Capitals:" << std::endl;
    for (pair<const string, const string> elem : capitalsMap) {
        cout << getCapital(elem.first) << std::endl;
    }

    // Problem 3
    CourseCatalog c;
    c.addCourse("TDT4110","Informasjonsteknologi grunnkurs");
    c.addCourse("TDT4102","Prosedyre- og objektorientert programmering");
    c.addCourse("TMA4100", "Matematikk 1");
    cout << c << endl;
    
    c.removeCourse("TDT4102");
    cout << c << endl;

    c.addCourse("TDT4102","Prosedyre- og objektorientert programmering");
    c.exportCourseCatalog("c");
    c.loadCourseCatalog("courseCatalog.csv");
    cout << c << endl;

    // Problem 4
    std::filesystem::path temperatureFile{"temperatures.txt"};
    std::ifstream temp_file{temperatureFile};
    Temps t;
    temp_file >> t; 
    cout << t.max << t.min << endl;

    return 0;
}


/* Teorioppgaver
2b) 

int main(){ 
    std::cout << "Capitals:" << std::endl;
    for (pair<const string, const string> elem : capitalsMap) {
    cout << getCapital(elem.first) << std::endl;
    }
}

Feilen skjer fordi ved å bruke [] operatoren forsøker kompilatoren å endre
map-et, men siden det er definert som constatn, vil ikke dette gå. Ved
å bruke .at() kan man få hentet ut verdien som ligger der.

*/