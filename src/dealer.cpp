#include "dealer.h"

bool Dealer::ShouldHit() const
{
    return (m_hand.GetScore() < 17);
}

const Hand &Dealer::GetHand() const
{
    return m_hand;
}

void Dealer::AddCard(const Card &card)
{
    m_hand.AddCard(card);
}

void Dealer::ResetHand()
{
    m_hand.ClearHand();
}
