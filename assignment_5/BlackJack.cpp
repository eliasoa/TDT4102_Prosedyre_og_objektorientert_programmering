#include "includes.hpp"

BlackJack::BlackJack(/* args */)
{
}

int BlackJack::getCardValue(Card card){
    Rank rank = card.getRank();
    if (rank == Rank::king || rank == Rank::queen || rank == Rank::jack)
    {
        return 10;
    }
    if (isAce(card))
    {
        return 11;
    }
    else
    {
        return static_cast<int>(rank);
    }
}

int BlackJack::getHandScore(vector<Card> hand){
    int firstCard{0};
    int lastCard{static_cast<int> (hand.size())};
    int sum{0};
    for (int cardNumber = firstCard; cardNumber < lastCard; cardNumber++)
    {
        Card card = hand.at(cardNumber);
        int cardValue = getCardValue(card);
        if (cardValue == 11)
        {
            if (sum + cardValue > 21)
            {
                cardValue = 1;
            }
            else
            {
                cardValue = 11;
            }
        }
        sum += cardValue;
    }
    return sum;
}

bool BlackJack::askPlayerDrawCard(){
    cout << "Do you want another card? y/n" << endl;
    char playerInput;
    cin >> playerInput;
    if (playerInput == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BlackJack::drawPlayerHand(){
    Card card = deck.drawCard();
    playerHand.push_back(card);
    playerHandSum = getHandScore(playerHand);
}

void BlackJack::drawDealerHand(){
    Card card = deck.drawCard();
    dealerHand.push_back(card);
    dealerHandSum = getHandScore(dealerHand);
}

void BlackJack::playGame(){
    bool playerOver = false;

    deck.shuffle();
    cout << "/////////////////////GAME START//////////////////////" << endl;
    drawPlayerHand();
    drawDealerHand();
    drawPlayerHand();
    drawDealerHand();
    Card playerFirstCard = playerHand.front();
    Card playerSecondCard = playerHand.back();
    Card dealersCard = dealerHand.back();
    cout << "Dealers card is " << dealersCard.toString() << "\n" <<
    "Your cards are " << playerFirstCard.toString() << " and " << 
    playerSecondCard.toString() << "Your hand is now " << playerHandSum << endl;

    while (playerHandSum < 21){
        if (askPlayerDrawCard())
        {
            drawPlayerHand();
                cout << "The card is " << playerHand.back().toString() 
                << ". Your hand is now " << playerHandSum << endl;
            if (playerHandSum > 21)
            {
                playerOver = true;
            }
            
        }
        else
        {
            break;
        }
    }
     
    while (dealerHandSum < 17  && playerOver == false)
    {
        drawDealerHand();
        cout << "The dealer drew " << dealerHand.back().toString() << "." << endl;
    }

    
    if (playerHandSum == 21 && dealerHandSum != 21)
    {
        cout << "You won with a BlackJack!" << endl;
    }
    else if (playerHandSum > dealerHandSum && playerOver == false)
    {
        cout << "You won with " << playerHandSum << " and the dealer had " << dealerHandSum << endl;
    }
    
    else if (playerOver == false &&  dealerHandSum > 22)
    {
        cout << "You won with " << playerHandSum << "and the dealer had " << dealerHandSum << endl;
    }
    else
    {
        cout << "The house won :( with " << dealerHandSum << endl;
    }
};


bool isAce(Card card){
    if (card.getRank() == Rank::ace)
    {
        return true;
    }
    else
    {
        return false;
    }
}