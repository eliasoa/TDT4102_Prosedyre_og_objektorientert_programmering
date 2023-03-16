#include "includes.hpp"

string suitToString(const Suit& suit){
    return suitStringMap.at(suit);
}

string rankToString(const Rank& rank){
    return rankStringMap.at(rank);
}

Card::Card(Suit suit, Rank rank) : s{suit}, r{rank}{};
// {
//     s = suit;
//     r = rank;
// };
Suit Card::getSuit(){
    return s;
}

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    return rankToString(r) + " of " + suitToString(s);
}