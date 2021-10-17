#pragma once


enum class Cellvalue
{
	WATER,
	DECK
};

class Cell
{
	Cellvalue value;
	bool state;

public:
	Cell(Cellvalue value = Cellvalue::WATER, bool state = false) 
		: value{ value }, state{ state }{}

	Cellvalue& Value()  // сетер и гетер
	{
		return value;
	}

	bool& State()
	{
		return state;
	}
};

