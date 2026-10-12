#include <iostream>
#include <string>
#include "card.h"


const std::string cardSuits[4] = {"HEART", "CLUB", "DIAMOND", "SPADE"};
const std::string cardValues[13] = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

void Card::PrintCard() const 
{
    std::cout<<cardSuits[m_suit]<<" "<<cardValues[m_value]<<std::endl;
}
