#pragma once
#include <vector>
#include "hand.h"

class Dealer
{
    public:
        Dealer(){};
        bool ShouldHit() const;
    private:
        Hand m_hand;
};