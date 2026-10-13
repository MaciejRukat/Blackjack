#pragma once
#include <vector>
#include "hand.h"

class Player
{
    public:
        Player(int money, int numberOfHands);
        int GetMoney() const;
        void DepositMoney(int money);
        
    private:
        std::vector<Hand> m_hands;
        int m_money = 0;
        int m_numberOfHands = 1;
};