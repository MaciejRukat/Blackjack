#pragma once
#include <string>

enum SUIT {HEART, CLUB, DIAMOND, SPADE}; 
enum VALUE {ACE, TWO, THREE, FOUR, FIVE, SIX,SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card {
    public:
        Card(SUIT suit, VALUE value);
        SUIT GetSuit() const;
        VALUE GetValue() const;
        void PrintCard() const;
    private:
        SUIT m_suit;
        VALUE m_value;
};

