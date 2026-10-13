#pragma once
#include <vector>
#include "card.h"

enum STATE{ACTIVE, STAND, BUST, WIN, BLACKJACK};

class Hand {
    public:
        Hand(int bet);
        void AddCard(const Card& card);
        void PrintHand();
        int GetScore() const;
        STATE GetState() const;
        void SetState(STATE state); 

    private:
        void ClearHand();
        void CountScore();
        int GetReward();
        std::vector<Card> m_hand;
        STATE m_state;
        int m_score;
        int m_bet;
};