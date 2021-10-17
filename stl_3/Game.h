#pragma once
#include <array>
#include "Player.h"
#include "ViewPort.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

enum TypePlayer
{
	HUMAN,
	COMPUTER
};

class Game
{
	std::array<Player*, 2> players;
	bool order;
	ViewPort view;

public:
	Game();
	void Init();
	void Play();
	void PlayRand();
	void Win();
	void Print();
	~Game();
	void Print_Sea_Board();
};

