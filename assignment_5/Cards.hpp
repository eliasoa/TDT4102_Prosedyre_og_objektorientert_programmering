#pragma once

#include "includes.hpp"

enum class Suit {clubs = 1, diamonds, hearts, spades};

enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

/// @brief Maps from enum to string
const std::map<Suit, string> suitStringMap {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"},
};

/// @brief Function that returns the Suit as a string
/// @param  enum Suit
/// @return string of element in the Suit enum
string suitToString(const Suit& suit);

const std::map<Rank, string> rankStringMap {
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"},
};

/// @brief Function that returns the rank as a string
/// @param rank Rank
/// @return string of element in the Rank enum
string rankToString(const Rank& rank);

class Card
{
private:
    Suit s;
    Rank r;
public:
    /// @brief Card constructor
    /// @param suit 
    /// @param rank 
    Card(Suit suit, Rank rank); 
    
    /// @brief Function that returns the suit of the card
    /// @return suit
    Suit getSuit();

    /// @brief Function that returns the rank of the card 
    /// @return rank
    Rank getRank();

    /// @brief Function that returns a string representation of the card
    /// @return string, e.g "Ace of Spades"
    string toString();
};