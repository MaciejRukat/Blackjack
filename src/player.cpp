#include <iostream>
#include "player.h"

Player::Player(int money):m_money(money){}

int Player::GetMoney() const
{
    return m_money;
}

void Player::RecieveReward(int reward)
{
    m_money += reward;
}

const Hand &Player::GetHand(size_t index) const
{
    return m_hands.at(index);
}

size_t Player::GetNumberOfHands() const
{
    return m_hands.size();
}

void Player::DepositMoney(int money)
{
    m_money += money;
}

void Player::AddHand(int bet)
{
    m_hands.push_back(Hand(bet));
}

void Player::AddCard(const Card &card, size_t index)
{
    m_hands.at(index).AddCard(card);
}

void Player::ResetHands()
{
    m_hands.clear();
}
