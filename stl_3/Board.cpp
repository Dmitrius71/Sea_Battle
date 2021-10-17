#include "Board.h"
#include "Cell.h"

void Board::StatusRestart()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j{}; j < 10; j++)
			board[i][j].State() = false;
	}
}

Board::Board()

{
}

bool Board::AddShip(int row, int col, int size, ShipDirection direction)
{
	bool isOk{ true };
	for (int i = 0; i < size; i++)
	{
		if (direction == ShipDirection::HORIZONTAL)
		{
			if (col + i > 9)
			{
				isOk = false;
				break;
			}
			isOk = isOk && !board[row][col + i].State();
		}
		else
		{
			if (row + i > 9)
			{
				isOk = false;
				break;
			}
			isOk = isOk && !board[row + i][col].State();
		}
	}
	if (!isOk)
		return false;

	if (direction == ShipDirection::HORIZONTAL)
		isOk = isOk && (col + size - 1) < 10;
	else
		isOk = isOk && (row + size - 1) < 10;

	if (!isOk)
		return false;

	ships.push_back(new Ship(size, direction, { row, col }));

	for (int i = 0; i < size; i++)
	{
		if (direction == ShipDirection::HORIZONTAL)
			board[row][col + i].Value() = Cellvalue::DECK;
		else
			board[row + i][col].Value() = Cellvalue::DECK;
	}
	for (int i = -1; i < size + 1; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (direction == ShipDirection::HORIZONTAL)
			{
				if (row + j < 0 || col + i < 0 || row + j > 9 || col + i > 9)
					continue;
				board[row + j][col + i].State() = true;
			}
			else
			{
				if (row + i < 0 || col + j < 0 || row + i > 9 || col + j > 9)
					continue;
				board[row + i][col + j].State() = true;
			}
		}
	}
	return true;
}



// тоже, что и shootCheck, но не делает €чейку "стрел€ной"
ShootState Board::ShootPrint(int row, int col)
{
	if (board[row][col].Value() == Cellvalue::WATER)
		return ShootState::MISS;

	for (Ship* ship : ships)
	{
		if (ship->GoodCells() == 0)
			continue;
		bool isHit{ false };
		for (int i = 0; i < ship->Size(); i++)
		{
			if (ship->Direction() == ShipDirection::HORIZONTAL)
				isHit = isHit || (row == ship->Row() && col == ship->Col() + i);
			else
				isHit = isHit || (row == ship->Row() + i && col == ship->Col());
		}
		if (isHit)
		{
			if (ship->GoodCells() == 0)
			{
				for (int i = -1; i < ship->Size() + 1; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						if (ship->Direction() == ShipDirection::HORIZONTAL)
						{
							if (row + j < 0 || col + i < 0 || row + j > 9 || col + i > 9)
								continue;
							board[row + j][col + i].State() = true;
						}
						else
						{
							if (row + i < 0 || col + j < 0 || row + i > 9 || col + j > 9)
								continue;
							board[row + i][col + j].State() = true;
						}
					}
				}
				return ShootState::KILL;
			}
			return ShootState::HIT;
		}
	}
}

ShootState Board::ShootCheck(int row, int col)
{
	board[row][col].State() = true; // выстрел произошЄл
	if (board[row][col].Value() == Cellvalue::WATER)
		return ShootState::MISS;

	for (Ship* ship : ships)
	{
		if (ship->GoodCells() == 0)
			continue;
		bool isHit{ false };
		for (int i = 0; i < ship->Size(); i++)
		{
			if (ship->Direction() == ShipDirection::HORIZONTAL)
				isHit = isHit || (row == ship->Row() && col == ship->Col() + i);
			else
				isHit = isHit || (row == ship->Row() + i && col == ship->Col());
		}
		if (isHit)
		{
			ship->GoodCells()--;
			if (ship->GoodCells() == 0)
			{
				for (int i = -1; i < ship->Size() + 1; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						if (ship->Direction() == ShipDirection::HORIZONTAL)
						{
							if (ship->Row() + j < 0 || ship->Col() + i < 0 || ship->Row() + j > 9 || ship->Col() + i > 9)
								continue;
							board[ship->Row() + j][ship->Col() + i].State() = true;
						}
						else
						{
							if (ship->Row() + i < 0 || ship->Col() + j < 0 || ship->Row() + i > 9 || ship->Col() + j > 9)
								continue;
							board[ship->Row() + i][ship->Col() + j].State() = true;
						}
					}
				}
				return ShootState::KILL;
			}
			return ShootState::HIT;
		}
	}
}

const std::array<std::array<Cell, 10>, 10>& Board::GetBoard()
{
	return board;
}

bool Board::ShipsCheck()
{
	bool shipcheck{ true }; // все корабли убиты
	for (Ship* ship : ships)
	{
		shipcheck = shipcheck && (ship->GoodCells() == 0); // если хоть один жив - shipcheck = false
	}
	return shipcheck;
}
