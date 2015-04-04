#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

#include "Board.h"
#include "GameEntity.h"

namespace logic
{
	class Game;
}

class logic::Game
{
	//Private:
	logic::Board board;
	logic::GameEntity player;

	std::vector<logic::GameEntity> attackers;
	std::vector<logic::GameEntity> defenders;

	// The game will finish after MAX_ROUNDS are completed.
	int currentRound;

	// It is used to end the round loop.
	bool isRoundOver;

	void init();

	void initRound();

	// Checks if the game or round is over and updates the state.
	void updateState();

public:

	Game();

	void run();	
	
};

#endif //_GAME_H_