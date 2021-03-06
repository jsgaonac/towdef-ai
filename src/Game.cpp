#include "Game.hpp"

#include "findpath.hpp"

#include <iostream>

logic::Game::Game(ui::UI* uiInstance)
{
	setUI(uiInstance);
}

void logic::Game::setUI(ui::UI* uiInstance)
{
	uiPtr = uiInstance;
	uiPtr->setGameLoop(&logic::Game::gameLoop);;
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

	entityManager.restartEntities(logic::EntityType::PLAYER);

	board.reset();

	clock.restart();

	shortestPath.clear();

}

void logic::Game::initRound(const std::vector<bool>& chromosome)
{
	entityManager.placeDefendersOnBoard(board, chromosome);

	calculateShortestPath(chromosome, shortestPath);

	if (shortestPath.size() == 0)
	{
		std::cout << "No hay camino!" << std::endl;
		isRoundOver = true;

		// There's no path, so penalize.
		score -= SUB_BLOCK_PATH;
	}

	if (chromosome[0] == 1)
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

double logic::Game::run(const std::vector<bool>& chromosome, int speed_ms)
{
	ticks = speed_ms;

	init();
	initRound(chromosome);

	uiPtr->create(WINDOW_W, WINDOW_H, WINDOW_BPP);
	uiPtr->show(this);

	int playerLife = entityManager.getPlayer()->getHealth();

	// Give points for each attacker killed.
	score +=  (ATTACKERS_ALLOC - entityManager.getNumberOfAttackers()) * ADD_DESTROY_POINTS;

	// Give points for each unit of life.
	score += (playerLife * ADD_LIFE_POINTS);

	// Take points for each tower placed.
	score -= (entityManager.getNumberOfTowers() * SUB_NUMBER_OF_TOWERS);

	if (playerLife <= 0)
	{
		score -= SUB_TOWER_DESTROYED;
	}

	double scoreNormalized = (score - MIN_VALUE) / (MAX_VALUE - MIN_VALUE);

	return scoreNormalized;
}

const logic::Board& logic::Game::getBoard()
{
	return board;
}