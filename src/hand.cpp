#include<iostream>
#include"hand.h"

Hand::Hand(){}

Hand::Hand(int bet):m_bet(bet)
{
    m_score = 0; 
}

void Hand::AddCard(const Card& card)
{
    m_hand.push_back(card);
    CountScore();
}

void Hand::ClearHand()
{
    m_hand.clear();
    m_score = 0;
}

void Hand::PrintHand() const
{
    for(size_t i = 0; i < m_hand.size();++i)
    {
        m_hand[i].PrintCard();
    }
}

const std::vector<Card>& Hand::GetCards() const
{
    return m_hand;
}

int Hand::GetScore() const
{
    return m_score;
}

int Hand::GetBet() const
{
    return m_bet;
}

size_t Hand::GetNumberofCards() const
{
    return m_hand.size();
}

bool Hand::IsBlackjack() const
{
    return (m_hand.size() == 2 && m_score == 21);
}

bool Hand::IsBust() const
{
    return (m_score > 21);

}

void Hand::CountScore()
{
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