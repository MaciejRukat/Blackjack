#include <iostream>
#include "deck.h"
#include "hand.h"

int main() {
    // Deck deck;
    // deck.ShuffleDeck();
    // // deck.PrintDeck();
    // Card karta = deck.DrawCard();
    // karta.PrintCard();

    Hand hand(200);
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

    hand.AddCard(as);
    hand.AddCard(k);
    hand.AddCard(k);
    std::cout<<hand.GetScore();
    hand.GetCards()[0].PrintCard();

    return 0;
}