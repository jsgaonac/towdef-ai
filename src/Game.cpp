#include "Game.hpp"

#include "findpath.hpp"

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

	if (!entityManager.allocateAttackers(30))
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

void logic::Game::initRound(std::vector<bool>& cromosome)
{
	activeAttackers = 30;

	entityManager.placeDefendersOnBoard(board, cromosome);

	calculateShortestPath(cromosome, shortestPath);

	if (shortestPath.size() == 0)
	{
		std::cout << "No hay camino!" << std::endl;
	}
}

void logic::Game::updateState()
{
	if (activeAttackers == 0 || entityManager.getPlayer()->getHealth() <= 0)
	{
		isRoundOver = true;
	} 
	
}

bool logic::Game::gameLoop()
{
	if (!isRoundOver)
	{
		entityManager.updateAttackers(board);
		updateState();
	}

	return true;
}

float logic::Game::run(std::vector<bool>& cromosome)
{
	init();
	initRound(cromosome);

	uiPtr->create(WINDOW_W, WINDOW_H, WINDOW_BPP);
	uiPtr->show(this);

	return score;
}

const logic::Board& logic::Game::getBoard()
{
	return board;
}