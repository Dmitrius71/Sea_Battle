#pragma once
#include "Player.h"
#include "HumanPlayer.h"

enum Side
{
	UNKNOWN,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class ComputerPlayer : public Player
{
	Player* hp;
	Coord c;
	int countOfHit;
	Side side;
public:
	ComputerPlayer(Player* hp);
	virtual void SetShips() override;
	virtual Coord Round() override;
	virtual ~ComputerPlayer();
	void SetPlayerHit(Coord coord);
	void ChangeSide();
	void SetSide();
};