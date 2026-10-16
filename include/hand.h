#pragma once
#include <vector>
#include "card.h"

class Hand {
    public:
        Hand();
        Hand(int bet);
        void AddCard(const Card& card);
        void PrintHand(bool onlyFirst = false) const;
        const std::vector<Card>& GetCards() const;
        int GetScore() const;
        int GetBet() const;
        size_t GetNumberofCards() const;
        void ClearHand();
        void Double();
        bool IsBlackjack() const;
        bool IsBust() const;


    private:
        void CountScore();
        std::vector<Card> m_hand;
        int m_score;
        int m_bet;
};