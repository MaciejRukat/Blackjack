#include "dealer.h"

bool Dealer::ShouldHit() const
{
    return (m_hand.GetScore() < 17);
}