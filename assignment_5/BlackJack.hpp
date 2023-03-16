#pragma once
#include "includes.hpp"

class BlackJack
{
private:
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum;
    int dealerHandSum;    
public:
    /// @brief Constructor
    BlackJack(/* args */);
    
    /// @brief Function that returns the value of the card
    /// @param card 
    /// @return int
    int getCardValue(Card card);
    	
    /// @brief Function that returns the value a players hand
    /// @param hand 
    /// @return int
    int getHandScore(vector<Card> hand);

    /// @brief Function that ask wether the player wants another card or not
    bool askPlayerDrawCard();

    /// @brief Function that adds a card to the players hand and calculates its sum
    void drawPlayerHand();

    /// @brief Function that adds a card to the dealers hand and calculates its sum
    void drawDealerHand();

    /// @brief Function that starts a round of BlackJack
    void playGame();
};

/// @brief Function that checks if a card has the rank 'Ace'
/// @param card 
/// @return true or false
bool isAce(Card card);
