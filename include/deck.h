#pragma once
#include <vector>
#include <random>
#include "card.h"

class Deck {
    public:
        Deck();
        void ShuffleDeck();
        Card DrawCard();
        void PrintDeck() const;
        size_t GetDeckSize() const;

    private:
        void InitializeDeck();
        std::vector<Card> m_cards;
        std::mt19937 m_rng;
};