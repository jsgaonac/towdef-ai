#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

#include <SFML/System.hpp>

#include "Board.hpp"
#include "Entity.hpp"
#include "EntityManager.hpp"
#include "UI.hpp"

namespace logic
{
	class Game;
}

class logic::Game
{
	//Private

	ui::UI* uiPtr;

	logic::Board board;

	logic::EntityManager entityManager;

	// Timer is used so game entities can move based on time.
	sf::Clock clock;

	// The game will finish after MAX_ROUNDS are completed.
	int currentRound;

	// It is used to end the round loop.
	bool isRoundOver;

	// Allocates all the entities needed to start the game and sets their values to their default.
	void init();

	// Every round is different, so in each round the entities will need to be initialized.
	void initRound();

	// Checks if the game or round is over and updates the state.
	void updateState();

	/** This is the most important method! In here, we'll control and develop the game
		mechanics. This method must be passed to the UI instance so it can execute it.
		We should not call this directly.
		Returns FALSE if the game is over.
	**/
	bool gameLoop();

public:

	Game(ui::UI* uiInstance);

	void run();	
	
};

#endif //_GAME_H_