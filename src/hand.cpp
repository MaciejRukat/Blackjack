#include<iostream>
#include"hand.h"

Hand::Hand(int bet):m_bet(bet)
{
    m_state = ACTIVE;
}

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

int Hand::GetScore() const
{
    return m_score;
}

STATE Hand::GetState() const
{
    return m_state;
}

void Hand::SetState(STATE state)
{
    m_state = state;
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

int Hand::GetReward()
{
    switch (m_state)
    {
    case BUST:
        return 0;
        break;
    case WIN:
        return m_bet * 2;
        break;
    case BLACKJACK:
        return m_bet * 3/2;
        break;
    default:
        break;
    }
}