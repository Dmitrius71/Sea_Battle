#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(std::string name) : Player(name)
{
}

void HumanPlayer::SetShips()
{
	int shipSize[5] = { 0, 4, 3, 2, 1 };

	ViewPort view;
	while (true)
	{
		view.ShowShips(shipSize);
		int currsize;
		ShipDirection direction;
		Coord coord;
		do
		{
			currsize = view.GetShipSize();
			if (shipSize[currsize] > 0)
			{
				shipSize[currsize]--;
				break;
			}
		} while (true);

		direction = view.GetShipDirection();

		do
		{
			coord = view.GetShipCoordinate();
		} while (!board.AddShip(coord.row, coord.col, currsize, direction));

		bool zero{};
		for (int i = 1; i < 5; i++)
		{
			zero = zero || (bool)shipSize[i];
		}
		if (zero == 0)
		{
			board.StatusRestart();
			break;
		}
	}
}

Coord HumanPlayer::Round()
{
	ViewPort view;
	Coord coord;
	coord = view.GetShootCoordinate();
	return coord;
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::SetShipsRand()
{

	int shipSize[5] = { 0, 4, 3, 2, 1 };

	ViewPort view;
	while (true)
	{
		//view.ShowShips(shipSize);
		int currsize;
		ShipDirection direction;
		Coord coord;
		do
		{
			currsize = view.GetShipSizeRand();
			if (shipSize[currsize] > 0)
			{
				shipSize[currsize]--;
				break;
			}
		} while (true);

		direction = view.GetShipDirectionRandom();

		do
		{
			coord = view.GetShipCoordinateRand();
		} while (!board.AddShip(coord.row, coord.col, currsize, direction));

		bool zero{};
		for (int i = 1; i < 5; i++)
		{
			zero = zero || (bool)shipSize[i];
		}
		if (zero == 0)
		{
			board.StatusRestart();
			break;
		}
	}
}
