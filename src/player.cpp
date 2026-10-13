#include <iostream>
#include "player.h"

Player::Player(int money, int numberOfHands):m_money(money), m_numberOfHands(numberOfHands){}

void Player::DepositMoney(int money)
{
    m_money += money;
}

int Player::GetMoney() const
{
    return m_money;
}

