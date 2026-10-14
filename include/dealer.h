#pragma once
#include "hand.h"

class Dealer
{
    public:
        Dealer(){};
        bool ShouldHit() const;
         const Hand& GetHand() const;
        void AddCard(const Card& card);
        void ResetHand();
    private:
        Hand m_hand;
};