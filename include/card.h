#pragma once
#include <string>

enum SUIT {HEART, CLUB, DIAMOND, SPADE}; 
enum VALUE {ACE, TWO, THREE, FOUR, FIVE, SIX,SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

class Card {
    public:
        Card(SUIT suit, VALUE value) : m_suit(suit), m_value(value) {}
        SUIT GetSuit() const { return m_suit; }
        VALUE GetValue() const { return m_value; }
        void PrintCard() const;
    private:
        SUIT m_suit;
        VALUE m_value;
};

