#pragma once
#include <map>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "Person.h"

enum class Campus{trd=1,aals,gjo};


const std::map<Campus,std::string> campusToString { 
    {Campus::trd , "Trondheim"}, 
    {Campus::aals , "Aalseund"}, 
    {Campus::gjo , "Gjovik"},
    };

std::ostream& operator<<(std::ostream& os, Campus c);

class Meeting
{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;

public:
    Meeting(int day, int startTime, int endTime, Campus location, std::string subject, const std::shared_ptr<Person> leader);

    int getDay(){return day;}
    int getStartTime(){return startTime;}
    int getEndTime(){return endTime;}
    Campus getCampus(){return location;}
    std::string getSubject(){return subject;}
    const std::shared_ptr<Person> getLeader(){return leader;}

    void addParticipant(std::shared_ptr<Person>);
    std::vector<std::string> getParticipantsList();
    std::vector<std::shared_ptr<Person>> findPotentialCoDriving(Meeting otherMeeting) const;
};

std::ostream& operator<<(std::ostream& os, Meeting m);