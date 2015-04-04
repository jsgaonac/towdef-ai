#include "Game.h"

logic::Game::Game() : player(logic::EntityType::TOWER)
{
	init();
}

void logic::Game::init()
{
	currentRound = 0;
	isRoundOver = false;

	board.setPlayerAt(&player, BOARD_W - 1, BOARD_H - 1);
}

void logic::Game::initRound()
{
	switch (currentRound):
	{
		case 1:
		{
			// 10 attackers of 'private' class.
			int attackers = 10;

			// There's no need to clear the vector since it's empty in round 1.

			for (int i = 0; i < attackers ; ++i)
			{
				attackers.push_back(logic::GameEntity(logic::EntityType::PRIVATE));
			}
		}
	}

}

void logic::Game::updateState()
{
	// The round ends whether all the attackers have been destroyed 
	// or the player's tower has been destroyed.
	isRoundOver = attackers.size() == 0 || player.getHealth() <= 0;
}

void logic::Game::run()
{
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