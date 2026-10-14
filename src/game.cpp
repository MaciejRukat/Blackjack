#include <iostream>
#include <chrono>
#include <thread>
#include "game.h"

Game::Game(Player player, Dealer dealer, Deck deck, int startHands): m_player(player), m_dealer(dealer), m_deck(deck), m_startHands(startHands){}

void Game::DealInitialCards()
{   m_player.ResetHands();
    m_dealer.ResetHand();
    for(int i = 0; i < m_startHands; ++i)
    {
        int bet = 0;
        std::cout<<"Podaj wartość zakładu ręki nr. "<< i + 1 << ":\n";
        std::cin >> bet;
        //TODO walidacja betu
        m_player.AddHand(bet);
    }
    
    for(int i = 0; i < 2; ++i)
    {
        std::cout<<"Rozdaję kar†ę "<<i+1<<std::endl;

        for(int j = 0; j < m_startHands; ++j)
        {
            Card playerCard = m_deck.DrawCard();
            m_player.AddCard(playerCard, j);
            std::cout<<"Ręka "<<j + 1<<": ";
            m_player.GetHand(j).PrintHand();
            std::cout<<"\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        std::cout<<"\n";
        std::cout<<"Rozdaję kar†ę krupierowi"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Card dealerCard = m_deck.DrawCard();
        m_dealer.AddCard(dealerCard);
        if(i == 0) 
        {
            std::cout<<"Karta zakryta\n"<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        else 
        {
            std::cout<<"Karta zakryta ";
            m_dealer.GetHand().PrintHand(true);
            std::cout<<"\n";
        }
    }
}

void Game::PlayerMove()
{
    m_playerHandsStates.clear();

    for(size_t i = 0; i < m_player.GetNumberOfHands(); ++i)
    {
        Hand playerHand = m_player.GetHand(i);
        
        if(playerHand.IsBlackjack() == true) 
        {
            m_playerHandsStates.push_back(STAND);
            continue;
        }

        while(true)
        {
            std::cout<<"\nRęka "<<i + 1<<": ";
            playerHand.PrintHand();
            if(playerHand.IsBust())
            {
                std::cout << "BUST\n" <<"\n";
                m_playerHandsStates.push_back(BUST);
                break;
            }
            
            std::cout<<"\nWbierz ruch: 1 -> HIT, 2 -> STAND: \n";
            int playerChoice = 0;
            std::cin >> playerChoice;

            if(playerChoice == 2) 
            {
                m_playerHandsStates.push_back(STAND);
                break;
            }

            playerHand.AddCard(m_deck.DrawCard());
        }
    }

    Hand dealerHand = m_dealer.GetHand();
    std::cout<<"\nKrupier: ";
    dealerHand.PrintHand();
    while(m_dealer.ShouldHit())
    {
        dealerHand.AddCard(m_deck.DrawCard());
        dealerHand.PrintHand();    

        
    }


}
