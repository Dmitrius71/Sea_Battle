#pragma once
#include <string>
#include "Ship.h"
//#include "Player.h"
//#include "HumanPlayer.h"
//#include "ComputerPlayer.h"

class ViewPort
{
public:
	Coord GetShipCoordinate();
	Coord GetShipCoordinateRand();
	int GetShipSize();
	int GetShipSizeRand();
	void ShowShips(int array[]);
	ShipDirection GetShipDirection();
	ShipDirection GetShipDirectionRandom();
	Coord GetShootCoordinate();
	std::string GetHumanName();
	void ShowMiss(std::string name);
	void ShowHit(std::string name);
	void ShowKill(std::string name);
	void RoundStart(std::string name);
	void GameWin(std::string name);
	//void ShowFild(Player* player1, Player* player2);
};
