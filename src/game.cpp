#include <iostream>
#include "game.h"

Game::Game(Player player, Dealer dealer, Deck deck): m_player(player), m_dealer(dealer), m_deck(deck){}

void Game::DealInitialCards()
{
    int numberOfHands= m_player.GetNumberOfHands();
    
    for(int i = 0; i < numberOfHands; ++i)
    {
        int bet = 0;
        std::cout<<"Podaj wartość zakładu ręki nr. "<< i + 1 << ":\n";
        std::cin >> bet;
        m_player.AddHand(bet);
    }
    
    for(int i = 0; i < 2; ++i)
    {
        
    }
}
