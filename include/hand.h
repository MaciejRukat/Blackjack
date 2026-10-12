#pragma once
#include <vector>
#include "card.h"

enum STATE{ACTIVE, STAND, BUST};

class Hand {
    public:
        Hand(){};
        void AddCard(Card card);
        void ClearHand();
        void PrintHand();
        int GetScore(){return m_score;}

    private:
        void CountScore();
        std::vector<Card> m_hand;
        STATE m_state;
        int m_score;
};