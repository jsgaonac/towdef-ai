#include "Game.hpp"

logic::Game::Game(ui::UI* uiInstance)
{
	uiPtr = uiInstance;
}

void logic::Game::init()
{
	currentRound = 0;
	isRoundOver = false;
	
	entityManager.allocatePlayer();

	entityManager.allocateAttackers(50);

	entityManager.allocateDefenders(100);

	clock.restart();

	uiPtr->setGameLoop(&logic::Game::gameLoop);
}

void logic::Game::initRound(std::vector<bool>& gen)
{
	for (int i = 0; i < gen.size(); i++)
	{
		board.
	}
}

void logic::Game::updateState()
{
	
}

bool logic::Game::gameLoop()
{
	if (clock.getElapsedTime().asSeconds() > 10)
	{
		return false;
	}

	return true;
}

void logic::Game::run()
{
	init();

	uiPtr->create(WINDOW_W, WINDOW_H, WINDOW_BPP);
	uiPtr->show(this);
}