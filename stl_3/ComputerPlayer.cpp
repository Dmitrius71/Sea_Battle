#include "ComputerPlayer.h"
#include <iostream>
#include <time.h>

ComputerPlayer::ComputerPlayer(Player* hp) : Player()
{
	this->hp = hp;
	c = { -1, -1 };
	countOfHit = 0;
	side = Side::UNKNOWN;
}

void ComputerPlayer::SetShips()
{
	int shipSize[5] = { 0, 4, 3, 2, 1 };
	srand(time(nullptr));
	
	while (true)
	{
		int currsize;
		ShipDirection direction;
		Coord coord;

		for (int i = 4; i; i--)
		{
			if (shipSize[i] > 0)
			{
				shipSize[i]--;

				currsize = i;
				break;
			}
		}

		direction = (rand() % 2) ? ShipDirection::HORIZONTAL : ShipDirection::VERTICAL;

		do
		{
			coord.col = rand() % 10;
			coord.row = rand() % 10;
		} while (!board.AddShip(coord.row, coord.col, currsize, direction));

		bool zero{};
		for (int i = 1; i < 5; i++)
		{
			zero = zero || (bool)shipSize[i];
		}
		if (!zero)
		{
			board.StatusRestart();
			break;
		}
	}
	std::cout << "Computer sets of ships\n";
}

Coord ComputerPlayer::Round()
{
	ViewPort view;
	Coord coord;
	if (c.col < 0) // если нет подбитых кораблей стреляем случайно
		do
		{
			coord.col = rand() % 10;
			coord.row = rand() % 10;
		} while (hp->isShoot(coord));
	else
		while (true)
		{
			switch (side)
			{
			case UNKNOWN:
				SetSide();
				break;
			case LEFT:
				// если следующий ход - граница поля или в данное направление уже был выстрел, 
				// то меняем направление на противоположное
				if ((c.col - countOfHit < 0) || (hp->isShoot({ c.row, c.col - countOfHit })))
				{
					// если обстреляно с двух сторон меняем сторону 
					if (hp->isShoot({ c.row, c.col + 1 }))
					{
						countOfHit = 1;
						SetSide();
					}
					else
						ChangeSide();
					break;
				}
				coord.row = c.row;
				coord.col = c.col - countOfHit++;
				return coord;
			case RIGHT:
				if ((c.col + countOfHit > 9) || (hp->isShoot({ c.row, c.col + countOfHit })))
				{
					if (hp->isShoot({ c.row, c.col - 1 }))
					{
						countOfHit = 1;
						SetSide();
					}
					else
						ChangeSide();
					break;
				}
				coord.row = c.row;
				coord.col = c.col + countOfHit++;
				return coord;
			case UP:
				if ((c.row - countOfHit < 0) || (hp->isShoot({ c.row - countOfHit, c.col })))
				{
					if (hp->isShoot({ c.row + 1, c.col }))
					{
						countOfHit = 1;
						SetSide();
					}
					else
						ChangeSide();
					break;
				}
				coord.row = c.row - countOfHit++;
				coord.col = c.col;
				return coord;
			case DOWN:
				if ((c.row + countOfHit > 9) || (hp->isShoot({ c.row + countOfHit, c.col })))
				{
					if (hp->isShoot({ c.row - 1, c.col }))
					{
						countOfHit = 1;
						SetSide();
					}
					else
						ChangeSide();
					break;
				}
				coord.row = c.row + countOfHit++;
				coord.col = c.col;
				return coord;
			default:
				break;
			}
		}
	return coord;
}

ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::SetPlayerHit(Coord coord)
{
	if (coord.col < 0 || c.col < 0)
	{
		c.row = coord.row;
		c.col = coord.col;
		countOfHit++;
	}
	if (c.row < 0)
	{
		countOfHit = 0;
		side = Side::UNKNOWN;
	}
}

void ComputerPlayer::ChangeSide() // смена направления на противоположное
{
	switch (side)
	{
	case UNKNOWN:
		break;
	case UP:
		countOfHit = 1;
		side = Side::DOWN;
		break;
	case DOWN:
		countOfHit = 1;
		side = Side::UP;
		break;
	case LEFT:
		countOfHit = 1;
		side = Side::RIGHT;
		break;
	case RIGHT:
		countOfHit = 1;
		side = Side::LEFT;
		break;
	default:
		break;
	}
}

void ComputerPlayer::SetSide() // установка случайного направления
{
	int i = 1 + rand() % 4;
	switch (i)
	{
	case 1:
		side = Side::UP;
		break;
	case 2:
		side = Side::DOWN;
		break;
	case 3:
		side = Side::LEFT;
		break;
	case 4:
		side = Side::RIGHT;
		break;
	default:
		break;
	}
}
