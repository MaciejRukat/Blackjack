#include <stdio.h>
#include <vector>
#include "player.h"
#include "dealer.h"
#include "deck.h"

enum OUTCOME {WIN, LOSE, BLACKJACK, PUSH, BUST, NONE};

class Game
{
    public:
    Game(Player player, Dealer dealer, Deck deck, int startHands);
    void DealInitialCards();
    void PlayRound();
   
    
    private:
        Player m_player;
        Dealer m_dealer;
        Deck m_deck;
        int m_startHands;
        std::vector<bool> m_isHandBust;
        int InputBet(int handNumber);
        void DelayConsoleOutput(int milliseconds) const;
        OUTCOME DetermineOutcome(const Hand& playerHand, const Hand& dealerHand);
        int CalculateReward(OUTCOME outcome, int bet);
};