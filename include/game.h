#include <stdio.h>
#include <vector>
#include "player.h"
#include "dealer.h"
#include "deck.h"

enum STATE {ACTIVE, BUST, STAND}; 

class Game
{
    public:
    Game(Player player, Dealer dealer, Deck deck, int startHands);
    void DealInitialCards();
    void PlayerMove();
    
    private:
        Player m_player;
        Dealer m_dealer;
        Deck m_deck;
        int m_startHands;
        std::vector<STATE> m_playerHandsStates;
};