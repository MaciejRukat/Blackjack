#include "deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck()
{
    InitializeDeck();
    m_rng.seed(std::random_device{}());
}

void Deck::InitializeDeck()
{
    m_cards.clear();
    m_cards.reserve(52);
    for(int i = 0; i < 4; ++i)
    {
        SUIT suit = static_cast<SUIT>(i);
        for(int j = 0; j < 13; ++j)
        {
            VALUE value = static_cast<VALUE>(j);
            
            m_cards.push_back(Card(suit,value));
        }
    }
}

void Deck::ShuffleDeck()
{
    std::shuffle(std::begin(m_cards),std::end(m_cards),m_rng);
}

void Deck::PrintDeck() const
{
    for(size_t i = 0; i < m_cards.size();++i)
    {
        m_cards[i].PrintValue();
    }
}

size_t Deck::GetDeckSize() const 
{
    return m_cards.size();
}

Card Deck::DrawCard()
{
    if(m_cards.size() == 0){
        InitializeDeck();
    }
    Card drawedCard = m_cards.back();
    m_cards.pop_back();
    return drawedCard;
}