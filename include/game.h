#include <stdio.h>
#include "player.h"
#include "dealer.h"
#include "deck.h"
class Game
{
    public:
    Game(Player player, Dealer dealer, Deck deck);
    void DealInitialCards();
    
    private:
        Player m_player;
        Dealer m_dealer;
        Deck m_deck;
};