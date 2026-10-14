#pragma once
#include <vector>
#include "hand.h"

class Player
{
    public:
        Player(int money);
        int GetMoney() const;
        const Hand& GetHand(size_t index) const;
        size_t GetNumberOfHands() const;
        void DepositMoney(int money);
        void AddHand(int bet);
        void AddCard(const Card& card, size_t index);
        void ResetHands();

    private:
        std::vector<Hand> m_hands;
        int m_money = 0;
};