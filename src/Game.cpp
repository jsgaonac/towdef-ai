#include "Game.hpp"

logic::Game::Game()
{
	// Do nothing.
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
}

void logic::Game::initRound()
{
	switch (currentRound)
	{
		case 1:
		{
			
		}
	}

}

void logic::Game::updateState()
{
	// The round ends whether all the attackers have been destroyed 
	// or the player's tower has been destroyed.
	isRoundOver = attackers.size() == 0 || player.getHealth() <= 0;
}

void logic::Game::tellAttack()
{
	for (int i = 0; i < attackers.size(); ++i)
	{
		attackers[i].move(clock.getElapsedTime().asSeconds());
	}
}

void logic::Game::run()
{
	init();

	// Game-loop
	while (player.getHealth() > 0 && currentRound < MAX_ROUNDS)
	{
		initRound();

		while(!isRoundOver)
		{
			// TODO: make the movements time-based.
			// TODO: make the attackers go to the player's tower.
			updateState();
		}
	}

}