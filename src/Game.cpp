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

	// Allocates 70 as maximum. We do not need more.
	entityManager.allocateAttackers(70);

	// Allocates 150. We may need more.
	entityManager.allocateDefenders(150);

	clock.restart();

	uiPtr->setGameLoop(&logic::Game::gameLoop);
}

void logic::Game::initRound()
{
	
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