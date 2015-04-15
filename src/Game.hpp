#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

#include <SFML/System.hpp>

#include "Board.hpp"
#include "Entity.hpp"

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

	// Timer is used so game entities can move based on time elapsed.
	sf::Clock clock;

	// The game will finish after MAX_ROUNDS are completed.
	int currentRound;

	// It is used to end the round loop.
	bool isRoundOver;

	void init();

	void initRound();

	// Checks if the game or round is over and updates the state.
	void updateState();

	// Tells the attackers to 'move'.
	void tellAttack();


public:

	Game();

	void run();	
	
};

#endif //_GAME_H_