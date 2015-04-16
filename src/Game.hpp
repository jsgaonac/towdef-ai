#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

#include <SFML/System.hpp>

#include "Board.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"

namespace logic
{
	class Game;
}

class logic::Game
{
	//Private
	logic::Board board;

	logic::EntityManager entityManager;

	// Timer is used so game entities can move based on time elapsed.
	sf::Clock clock;

	// The game will finish after MAX_ROUNDS are completed.
	int currentRound;

	// It is used to end the round loop.
	bool isRoundOver;

	// Allocates all the entities needed to start the game and sets the value to default.
	void init();

	// Every round is different, so in each round the entities will need to be initialized.
	void initRound();

	// Checks if the game or round is over and updates the state.
	void updateState();

	// Sets the position of the attackers to the respawn point.
	void restartAttackers();


public:

	Game();

	void run();	
	
};

#endif //_GAME_H_