#include <iostream>
#include <string>
#include "card.h"


const std::string cardSuits[4] = {"HEART", "CLUB", "DIAMOND", "SPADE"};
const std::string cardValues[13] = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

Card::Card(SUIT suit, VALUE value): m_suit(suit), m_value(value){}

SUIT Card::GetSuit() const 
{ 
    return m_suit; 
}

VALUE Card::GetValue() const
{
    return m_value;
}

void Card::PrintValue() const
{
    std::cout<<cardValues[m_value];
}
