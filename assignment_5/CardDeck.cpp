#include "includes.hpp"

CardDeck::CardDeck(){
    for (const auto& suit: suitStringMap)
    {
        for (const auto& rank: rankStringMap)
        {   
            Card c{suit.first, rank.first};
            cards.push_back(c);
        }
    }
}

void CardDeck::swap(int pos1, int pos2){
    Card temp = cards.at(pos1);
    cards.at(pos1) = cards.at(pos2);
    cards.at(pos2) = temp;
}

void CardDeck::print(){
    for (int i = 0; i < cards.size(); i++)
    {
        Card c = cards.at(i);
        cout << c.toString() << endl;
    }
}

void CardDeck::shuffle(){

    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0,cards.size()-1);
    for (int i = 0; i < cards.size(); i++)
    {
        int pos1 = distribution(generator);
        int pos2 = distribution(generator);
        CardDeck::swap(pos1,pos2);
    }
}

Card CardDeck::drawCard(){
    Card card = cards.back();
    cards.pop_back();
    return card;
}