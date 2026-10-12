#include <iostream>
#include "deck.h"
#include "hand.h"

int main() {
    // Deck deck;
    // deck.ShuffleDeck();
    // // deck.PrintDeck();
    // Card karta = deck.DrawCard();
    // karta.PrintCard();

    Hand hand;
    // hand.AddCard(karta);
    // hand.PrintHand();

    // hand.ClearHand();
    // hand.PrintHand();

    Card as(HEART,ACE);
    Card k(HEART,KING);
    Card nine(HEART,NINE);
    Card five(HEART,FIVE);
    Card ten(HEART,TEN);
    Card six(HEART,SIX);
    Card two(HEART,TWO);

    hand.AddCard(k);
    hand.AddCard(k);
    hand.AddCard(k);
    std::cout<<hand.GetScore();
    std::cout<<hand.GetState();

    return 0;
}