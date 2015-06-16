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

	// Mimimum elapsed time required to update the game.
	int ticks;

	// Timer is used so game entities can move based on time.
	sf::Clock clock;

	// The game will finish after MAX_ROUNDS are completed.
	int currentRound;

	// It is used to end the round loop.
	bool isRoundOver;

	// Stores the score of the game.
	double score;

	/* Stores the map coordinates of the shortest path from the respawn point 
	 	to the player tower */
	std::vector<Point> shortestPath;

	// Allocates all the entities needed to start the game and sets their values to their default.
	void init();

	// Every round is different, so in each round (in case there are more than one)
	// the entities will need to be initialized.
	// It also 'reads' the provided gen and 'puts' the player defense tower in the given
	// position.
	void initRound(const std::vector<bool>& chromosome);

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

	/* Takes the chromosome representing the defenders positions and the speed at which
	 the game will run, in milliseconds.
	 If speed_ms = 500, each 500 ms the game will update. If speed_ms = 0 the game
	 will update at each loop. */
	double run(const std::vector<bool>& chromosome, int speed_ms);

	void setUI(ui::UI* uiInstance);

	const logic::Board& getBoard();
	
};

#endif //_GAME_H_