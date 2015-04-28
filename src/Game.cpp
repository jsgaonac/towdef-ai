#include "Game.hpp"

#include <iostream>

logic::Game::Game(ui::UI* uiInstance)
{
	uiPtr = uiInstance;
}

void logic::Game::init()
{
	currentRound = 0;
	isRoundOver = false;
	score = 0;
	
	entityManager.allocatePlayer();

	if (!entityManager.allocateAttackers(50))
	{
		std::cout << "Atacantes => No se pudo asignar memoria." << std::endl;
	}

	if (!entityManager.allocateDefenders(100))
	{
		std::cout << "Defensores => No se pudo asignar memoria." << std::endl;
	}

	clock.restart();

	uiPtr->setGameLoop(&logic::Game::gameLoop);

}

void logic::Game::initRound(std::vector<bool>& gen)
{
	entityManager.placeDefendersOnBoard(board, gen);
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

float logic::Game::run(std::vector<bool>& gen)
{
	init();
	initRound(gen);

	uiPtr->create(WINDOW_W, WINDOW_H, WINDOW_BPP);
	uiPtr->show(this);

	return score;
}

const logic::Board& logic::Game::getBoard()
{
	return board;
}