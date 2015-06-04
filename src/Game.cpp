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

	if (!entityManager.allocateAttackers(ATTACKERS_ALLOC))
	{
		std::cout << "Atacantes => No se pudo asignar memoria." << std::endl;
	}

	if (!entityManager.allocateDefenders(DEFENDERS_ALLOC))
	{
		std::cout << "Defensores => No se pudo asignar memoria." << std::endl;
	}

	clock.restart();

	uiPtr->setGameLoop(&logic::Game::gameLoop);

}

void logic::Game::initRound(std::vector<bool>& cromosome)
{
	entityManager.placeDefendersOnBoard(board, cromosome);

	calculateShortestPath(cromosome, shortestPath);

	if (shortestPath.size() == 0)
	{
		std::cout << "No hay camino!" << std::endl;
		isRoundOver = true;

		// If the tower is blocked.
		if(cromosome[cromosome.size() - 1] == 1)
		{
			score -= SUB_TOWER_BLOCK;
		}

		// There's no path, so penalize.
		score -= SUB_BLOCK_PATH;
	}

	if (cromosome[0] == 1)
	{
		score -= SUB_RESPAWN_BLOCK;
	}
}

void logic::Game::updateState()
{
	if (entityManager.getNumberOfAttackers() == 0 || entityManager.getPlayer()->getHealth() <= 0)
	{
		isRoundOver = true;
	} 
}

bool logic::Game::gameLoop()
{
	if (!isRoundOver)
	{
		if (clock.getElapsedTime().asMilliseconds() >= ticks)
		{
			entityManager.updateAttackers(board, shortestPath);
			updateState();

			clock.restart();
		}

		return true;		
	}
	
	return false;
}

float logic::Game::run(std::vector<bool>& cromosome, int speed_ms)
{
	ticks = speed_ms;

	init();
	initRound(cromosome);

	uiPtr->create(WINDOW_W, WINDOW_H, WINDOW_BPP);
	uiPtr->show(this);

	// Give points for each attacker killed.
	score +=  (ATTACKERS_ALLOC - entityManager.getNumberOfAttackers()) * ADD_DESTROY_POINTS;

	// Give points for each unit of life.
	score += ((PLAYER_HEALTH - entityManager.getPlayer()->getHealth()) * ADD_LIFE_POINTS);

	// Take points for each tower placed.
	score -= (entityManager.getNumberOfTowers() * SUB_NUMBER_OF_TOWERS);

	return score / NORM_VALUE;
}

const logic::Board& logic::Game::getBoard()
{
	return board;
}