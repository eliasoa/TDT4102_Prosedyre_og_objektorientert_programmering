#pragma once

#include "includes.hpp"

class CardDeck
{
private:
    vector<Card> cards;
public:
    /// @brief Creates a card deck consisting of 52 cards of the class Card
    CardDeck();

    /// @brief Function that swaps the position of two cards i the 'cards' vector
    /// @param pos1 
    /// @param pos2 
    void swap(int pos1, int pos2);

    /// @brief Function that prints the card deck
    void print();

    /// @brief Function that shuffels the card deck
    void shuffle();

    /// @brief Function that draws the top card of the deck
    /// @return card
    Card drawCard();
};