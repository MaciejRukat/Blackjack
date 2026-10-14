#include <iostream>
#include <chrono>
#include <thread>
#include "game.h"
#include "input.h"

Game::Game(Player player, Dealer dealer, Deck deck, int startHands): m_player(player), m_dealer(dealer), m_deck(deck), m_startHands(startHands){}

void Game::DealInitialCards()
{   m_player.ResetHands();
    m_dealer.ResetHand();
    for(int i = 0; i < m_startHands; ++i)
    {
        int bet = InputBet(i+1);
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
            
        }

        std::cout<<"\n";
        std::cout<<"Rozdaję kar†ę krupierowi"<<std::endl;
        DelayConsoleOutput(1000);
        Card dealerCard = m_deck.DrawCard();
        m_dealer.AddCard(dealerCard);
        if(i == 0) 
        {
            std::cout<<"Karta zakryta\n"<<std::endl;
            DelayConsoleOutput(1000);
        }
        else 
        {
            std::cout<<"Karta zakryta ";
            m_dealer.GetHand().PrintHand(true);
            std::cout<<"\n";
            DelayConsoleOutput(1000);
        }
    }
}

int Game::InputBet(int handNumber)
{
    while (true)
    {
        std::cout << "Podaj wartość zakładu ręki nr. " << handNumber << ":\n";
        int bet = ReadInt();

        if (m_player.PlaceBet(bet))
            return bet;                 

        std::cout << "Nieprawidłowy zakład (saldo: " << m_player.GetMoney() << ").\n";
        std::cout << "1 -> dopłać pieniądze, 2 -> podaj nowy zakład:\n";
        if (ReadInt() == 1) m_player.InputMoney();
    }
}

void Game::PlayRound()
{
    for(size_t i = 0; i < m_player.GetNumberOfHands(); ++i)
    {
        const Hand& playerHand = m_player.GetHand(i);
        
        if(playerHand.IsBlackjack() == true) 
        {
            std::cout<<"\nRęka "<<i + 1<<": ";
            playerHand.PrintHand();
            std::cout << "BLACKJACK\n" <<"\n";
            continue;
        }

        bool isDouble = false;
        while(true)
        {
            std::cout<<"\nRęka "<<i + 1<<": ";
            playerHand.PrintHand();
            

            if(playerHand.IsBust())
            {
                std::cout << "\nBUST\n" <<"\n";
                break;
            }
            
            if(isDouble) break; 

            if(playerHand.GetNumberofCards() == 2) std::cout<<"\nWbierz ruch: 1 -> HIT, 2 -> STAND, 3 -> DOUBLE:\n";
            else std::cout<<"\nWbierz ruch: 1 -> HIT, 2 -> STAND:\n";
            
            int choice = 0;
            while (true)
            {
                choice = ReadInt();
                bool canDouble = (playerHand.GetNumberofCards() == 2);
                if (choice == 1 || choice == 2 || (choice == 3 && canDouble)) break;
                std::cout << "Niepoprawny wybór.\n";
            }

            if (choice == 2) 
            { 
                std::cout << "STAND\n\n"; 
                break; 
            }
            if (choice == 3) 
            {
                isDouble = true;
                std::cout << "DOUBLE\n\n";
            } 
            m_player.AddCard(m_deck.DrawCard(), i);
        }
        DelayConsoleOutput(1000);
    }

    const Hand& dealerHand = m_dealer.GetHand();
    std::cout<<"\nKrupier: ";
    dealerHand.PrintHand();
    while(m_dealer.ShouldHit())
    {
        m_dealer.AddCard(m_deck.DrawCard());
        dealerHand.PrintHand();    
    }

    for(size_t i = 0; i < m_player.GetNumberOfHands(); ++i)
    {
        const Hand& playerHand = m_player.GetHand(i);
        OUTCOME outcome = DetermineOutcome(playerHand, dealerHand);
        int reward = CalculateReward(outcome, playerHand.GetBet());
        if(reward > 0) m_player.RecieveReward(reward);
    } 
        
}

void Game::DelayConsoleOutput(int milliseconds) const
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

OUTCOME Game::DetermineOutcome(const Hand& playerHand, const Hand& dealerHand)
{
        if(playerHand.IsBust()) return BUST;
        if(playerHand.IsBlackjack()) return dealerHand.IsBlackjack() ? PUSH : BLACKJACK;
        if(dealerHand.IsBlackjack()) return LOSE;
        if(dealerHand.IsBust()) return WIN;
        if(playerHand.GetScore() > dealerHand.GetScore()) return WIN;
        if(playerHand.GetScore() == dealerHand.GetScore()) return PUSH;
        else return LOSE;       
}

int Game::CalculateReward(OUTCOME outcome, int bet)
{
    int reward = 0;
    
    switch (outcome)
    {
        case WIN:
            reward = bet*2;
            std::cout<<"\nWYGRAŁEŚ!\n";
            break;
        
        case BLACKJACK:
            reward = bet + bet * 3 / 2;
            std::cout<<"\nBLACKJACK\n";
            break;

        case PUSH:
            reward = bet;
            std::cout<<"PUSH\n ";
            break;

        case BUST:
            reward = 0;
            std::cout<<"BUST\nPrzegrałeś\n";
            break;

        case LOSE:
            reward = 0;
            std::cout<<"\nPrzegrałeś\n";
            break;

        case NONE:
            break;

        default:
            break;
    }
    return reward;
}
