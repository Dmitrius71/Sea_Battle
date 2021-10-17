#pragma once

struct Coord
{
	int row, col;
};

enum class ShipDirection
{
	HORIZONTAL,
	VERTICAL
};

class Ship
{
	int size, goodCells;
	ShipDirection direction;
	Coord coord;

public:
	Ship(int size, ShipDirection direction, Coord coord)
		: size{ size }, direction{ direction }, goodCells{ size }, coord{ coord }{}

	int Size();
	ShipDirection Direction();
	int& Row();
	int& Col();
	bool isLive();
	int& GoodCells();
};