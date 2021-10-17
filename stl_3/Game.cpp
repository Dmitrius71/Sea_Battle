#include "Game.h"


#include "Game.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Game::Game()
{
    players[TypePlayer::HUMAN] = new HumanPlayer(view.GetHumanName());
    players[TypePlayer::COMPUTER] = new ComputerPlayer(players[TypePlayer::HUMAN]);
    order = false;
}

void Game::Init()
{
   
        for (int i = 0; i < 2; i++)
                players[i]->SetShips();
 
}

void Game::Play()
{
  
    Print();


    while (true)
    {

        view.RoundStart(players[order]->Name());

        Coord coord = players[order]->Round();
        ShootState state = players[!order]->ShootCheck(coord);
        if (state == ShootState::MISS)
        {
            view.ShowMiss(players[order]->Name());
            if (players[order] == players[TypePlayer::COMPUTER])
                dynamic_cast<ComputerPlayer*>(players[order])->ChangeSide();
            order = !order;
        }
        if (state == ShootState::HIT)
        {
            view.ShowHit(players[order]->Name());
            if (players[order] == players[TypePlayer::COMPUTER])
            {
                dynamic_cast<ComputerPlayer*>(players[order])->SetPlayerHit(coord);
                Sleep(1000);
            }
        }
        if (state == ShootState::KILL)
        {
            view.ShowKill(players[order]->Name());
            if (players[order] == players[TypePlayer::COMPUTER])
            {
                dynamic_cast<ComputerPlayer*>(players[order])->SetPlayerHit({ -1, -1 });
                Sleep(1000);
            }
        }
        
        Print();
        if (players[!order]->GameCheck())
            break;
    }
}

void Game::PlayRand()
{
    Print();

    while (true)
    {

        view.RoundStart(players[order]->Name());

        Coord coord = players[order]->Round();
        ShootState state = players[!order]->ShootCheck(coord);
        if (state == ShootState::MISS)
        {
            view.ShowMiss(players[order]->Name());
            if (players[order] == players[TypePlayer::COMPUTER])
                dynamic_cast<ComputerPlayer*>(players[order])->ChangeSide();
            order = !order;
        }
        if (state == ShootState::HIT)
        {
            view.ShowHit(players[order]->Name());
            if (players[order] == players[TypePlayer::COMPUTER])
            {
                dynamic_cast<ComputerPlayer*>(players[order])->SetPlayerHit(coord);
                Sleep(1000);
            }
        }
        if (state == ShootState::KILL)
        {
            view.ShowKill(players[order]->Name());
            if (players[order] == players[TypePlayer::COMPUTER])
            {
                dynamic_cast<ComputerPlayer*>(players[order])->SetPlayerHit({ -1, -1 });
                Sleep(1000);
            }
        }
        Print();
        if (players[!order]->GameCheck())
            break;
    }

}


void Game::Win()
{
    view.GameWin(players[order]->Name());
}

void Game::Print()
{
    cout << "   \t";
    for (int i = 0; i < 55; i++)
    {
        cout << "-";
    }

    cout << "   \t";
    for (int i = 0; i < 55; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "   \t";
    for (int i = 0; i <= 10; i++)
    {
        cout << "| " << i << " |";
    }
    cout << "\t";
    for (int i = 0; i <= 10; i++)
    {
        cout << "| " << i << " |";
    }
    cout << endl;
    cout << "  \t";
    for (int i = 0; i < 55; i++)
    {
        cout << "-";
    }
    cout << "  \t";
    for (int i = 0; i < 55; i++)
    {
        cout << "-";
    }

    cout << endl;



    for (int i = 1; i < 10; i++)
    {
        cout << "\t";
        cout << "| " << i << " |";


        for (int j = 0; j < 10; j++)
        {
            bool temp = players[TypePlayer::HUMAN]->isShoot({ i, j });

            ShootState state = players[TypePlayer::HUMAN]->ShootPrint({ i, j });

            if (state == ShootState::MISS)
                if (temp)
                    std::cout << "| % |"; // промах
                else
                    std::cout << "| . |";  // море
            else if (state != ShootState::MISS && temp)
                std::cout << "| # |"; //убил
            else
                std::cout << "| $ |";  // корабли
            
        }

        cout << " \t";
        cout << "| " << i << " |";


        for (int j = 0; j < 10; j++)
        {
            if (!players[TypePlayer::COMPUTER]->isShoot({ i, j }))
                std::cout << "| X |";  // поле компа
            else
            {
                ShootState state = players[TypePlayer::COMPUTER]->ShootPrint({ i, j });
                if (state == ShootState::MISS)
                    std::cout << "| * |"; //промах
                else
                    std::cout << "| 0 |"; // попадание
            }

        }

        cout << endl;
        cout << "  \t";
        for (int j = 0; j < 55; j++)
        {
            cout << "-";
        }
        cout << "  \t";
        for (int j = 0; j < 55; j++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "  \t";
        for (int j = 0; j < 55; j++)
        {
            cout << "-";
        }
        cout << "  \t";
        for (int j = 0; j < 55; j++)
        {
            cout << "-";
        }


        cout << endl;

    }
}

Game::~Game()
{
    for (int i = 0; i < 2; i++)
    {
        delete players[i];
    }
}


