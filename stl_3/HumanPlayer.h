#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(std::string name);
	virtual void SetShips() override;
	virtual Coord Round() override;
	virtual ~HumanPlayer();
	virtual void SetShipsRand();


};


