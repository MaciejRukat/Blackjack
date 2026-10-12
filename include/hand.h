#pragma once
#include <vector>
#include "card.h"

enum STATE{ACTIVE, STAND, BUST, WIN, BLACKJACK};

class Hand {
    public:
        Hand(){m_state = ACTIVE;}
        void AddCard(const Card& card);
        void ClearHand();
        void PrintHand();
        int GetScore(){return m_score;}
        STATE GetState(){return m_state;}
        void Stand();

    private:
        void CountScore();
        void UpdateState();
        std::vector<Card> m_hand;
        STATE m_state;
        int m_score;
};