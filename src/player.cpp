#include <iostream>
#include "player.h"

Player::Player(int money, int numberOfHands):m_money(money), m_numberOfHands(numberOfHands){}

int Player::GetMoney() const
{
    return m_money;
}

int Player::GetNumberOfHands() const
{
    return m_numberOfHands;
}

void Player::DepositMoney(int money)
{
    m_money += money;
}

void Player::AddHand(int bet)
{
    m_hands.push_back(Hand(bet));
}
