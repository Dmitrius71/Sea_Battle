#pragma once
#include<array>
#include<vector>
#include "Ship.h"
#include"Global.h"
#include"Cell.h"


enum class ShootState
{
	MISS,
	HIT,
	KILL
};

class Board
{
	using cellArray = std::array<std::array<Cell, 10>, 10>;
	cellArray board;
	std::vector<Ship*> ships;



public:

	Board();
	bool AddShip(int row, int col, int size, ShipDirection direction);
	ShootState ShootPrint(int row, int col); // тоже, что и shootCheck, но не делает €чейку "стрел€ной"
	ShootState ShootCheck(int row, int col);
	const cellArray& GetBoard();
	bool ShipsCheck();
	void StatusRestart();
};

