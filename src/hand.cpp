#include<iostream>
#include"hand.h"

void Hand::AddCard(const Card& Card)
{
    m_hand.push_back(Card);
    CountScore();
    UpdateState();
}

void Hand::ClearHand()
{
    m_hand.clear();
    m_score = 0;
}
void Hand::PrintHand()
{
    for(size_t i = 0; i < m_hand.size();++i)
    {
        m_hand[i].PrintCard();
    }
}

void Hand::CountScore(){
    int aceCounter = 0;
    m_score = 0;
    for(size_t i = 0; i < m_hand.size(); ++i)
    {
        int value = m_hand[i].GetValue();
        if(value > ACE && value <= TEN)
        {
            m_score += value +1;
        } 
        else if(value > TEN) 
        {
            m_score += 10;
        }
        else
        {
            aceCounter++;
        }
        
    }
    if (aceCounter > 0)
    {
        if(m_score + 10 + aceCounter <= 21) m_score = m_score + 10 + aceCounter;
        else m_score = m_score + aceCounter;
    }
}

void Hand::UpdateState()
{
    if(m_score > 21)
    {
        m_state = BUST;
    }

    if(m_hand.size() == 2 && m_score == 21){
        m_state = BLACKJACK;
    }
}

void Hand::Stand()
{
    m_score = STAND;
}