#pragma once
#include <vector>
#include "hand.h"

class Player
{
    public:
        Player(int money): m_money(m_money){};
        void GetMoney() const{};
        void SetMoney();
        
    private:
        std::vector<Hand> hands;
        int m_money = 0
};