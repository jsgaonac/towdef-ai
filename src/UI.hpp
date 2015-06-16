#ifndef _UI_HPP_
#define _UI_HPP_

namespace ui
{
	class UI;	
}

namespace logic
{
	class Game;
}

namespace ai
{
	class Genetic;
}

// Pointer to a logic::Game method.
typedef bool (logic::Game::*gameMethodPtr)();

class ui::UI
{
protected:

	// We store the pointer to the game loop method so we can
	// call it whenever we want.
	gameMethodPtr loopMethod;

	ai::Genetic *geneticPtr;

public:

	UI();

	virtual void create(int w, int h, int bpp = 32) = 0;

	// In the UI implementation there should be a loop. In that
	// loop (execution loop) the method passed as argument will be
	// executed, as the UI manages the window therefore the game as well.
	// For example, if the game is not over, but I click on the window close
	// button, the game will end.
	// Nevertheless the game must tell the window when it is done running,
	// so that's why the Game Loop method must return a boolean value indicating
	//with TRUE that is not over, and with FALSE that it is over.
	virtual void setGameLoop(gameMethodPtr loopMethod) final;

	// This should start the UI loop.
	virtual void show(logic::Game* gameInstance) = 0;

	// Returns the average fitness.
	virtual double showGeneticStats() = 0;

	void setGenetic(ai::Genetic *genetic);

	virtual ~UI();
};

#endif