#include "Meeting.h"
#include <iostream>

/// @brief Overloading of << operator for Campus
/// @param os 
/// @param c 
/// @return 
std::ostream& operator<<(std::ostream& os, Campus c){
    return os << campusToString.at(c);
}

/// @brief Adds person to participant vector
/// @param shared_ptr<Person>
void Meeting::addParticipant(std::shared_ptr<Person> p){
    participants.push_back(p);
}

/// @brief Constructor for Meeting class that adds the leader to the participants list
/// @param day 
/// @param startTime 
/// @param endTime 
/// @param location 
/// @param subject 
/// @param leader 
Meeting::Meeting(int day, int startTime, int endTime, Campus location, std::string subject, const std::shared_ptr<Person> leader) : 
    day{day}, 
    startTime{startTime},
    endTime{endTime},
    location{location},
    subject{subject},
    leader{leader}
    {addParticipant(leader);}

/// @brief Returns the list of participants
/// @return 
std::vector<std::string> Meeting::getParticipantsList(){
    std::vector<std::string> participantsList;
    for (auto p:participants)
    {
        participantsList.push_back(p->getName());
    }  
    return participantsList;
}

/// @brief Overloading of the << operator for the Meeting class
/// @param os 
/// @param m 
/// @return 
std::ostream& operator<<(std::ostream& os, Meeting m){
    os << "Subject:\t" << m.getSubject() << "\n" << "Location:\t" << m.getCampus() << "\n" << "Start time:\t" << m.getStartTime() << "\n" << "End time:\t" << m.getEndTime() << "\n";
    os << "The participants are: ";
    std::vector<std::string> list = m.getParticipantsList();
    for (auto p:list)
    {
        os << p << ", ";
    }
    return os;
}

/// @brief Function that finds potential codriving persons
/// @param m Meeting
/// @return std::vector of std::shared_ptr<Person>
std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting otherMeeting) const {
    std::vector<std::shared_ptr<Person>> coDrivingParterList;

    std::vector<std::shared_ptr<Person>> participantsOfOtherMeeting = otherMeeting.participants;


    for (auto p:participantsOfOtherMeeting)
    {
        if (p->hasAvailableSeat())
        {
            if (day == otherMeeting.day && location == otherMeeting.location && abs(startTime - otherMeeting.startTime) < 1 && abs(endTime - otherMeeting.endTime) < 1)
            {
                coDrivingParterList.push_back(p);
            }
        }
    }
    return coDrivingParterList;
}