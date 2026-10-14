#include <iostream>
#include "deck.h"
#include "player.h"
#include "dealer.h"
#include "game.h"


int main() {
    Deck deck;
    Player player(200);
    Dealer dealer;
    Game game(player, dealer, deck, 2);
    game.DealInitialCards();
    game.PlayRound();
    return 0;
}