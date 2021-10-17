#include "Player.h"

Player::Player(std::string name)
{
	this->name = name;
}

bool Player::GameCheck()
{
	return board.ShipsCheck();
}

ShootState Player::ShootCheck(Coord coord)
{
	return board.ShootCheck(coord.row, coord.col);
}

ShootState Player::ShootPrint(Coord coord)
{
	return board.ShootPrint(coord.row, coord.col);
}

std::string Player::Name()
{
	return this->name;
}

bool& Player::isShoot(Coord coord)
{
	std::array<std::array<Cell, 10>, 10> b = board.GetBoard();
	return b[coord.row][coord.col].State();
}

Player::~Player()
{
}
