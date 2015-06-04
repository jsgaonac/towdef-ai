#include "EntityManager.hpp"
#include "defines.hpp"
#include "Util.hpp"

logic::EntityManager::EntityManager()
{
	attackersPool = nullptr;
	defendersPool = nullptr;
	playerPtr = nullptr;

	allocatedDefenders = -1;
	allocatedAttackers = -1;

	attackersSize = 0;
	defendersSize = 0;
}

bool logic::EntityManager::allocateAttackers(int n)
{
	// Do not allocate if the number of attackers
	// is less or equal, just update the attackers size.
	if (n <= allocatedAttackers)
	{
		setAttackersSize(n);
	}
	else
	{	// Allocate again.
		bool success = allocate(&attackersPool, n);

		if (success)
		{
			allocatedAttackers = n;
			// We set it to 1 because only 1 attackers will be active at the
			// beginning. Each tock this number will be incremented.
			setAttackersSize(1);
			initEntities(attackersPool, allocatedAttackers, logic::EntityType::ATTACK);
			return true;
		}
		else
		{
			return false;
		}
	}	

	return true;
}

void logic::EntityManager::setAttackersSize(int n)
{
	if (n <= allocatedAttackers)
	{
		attackersSize = n;
	}
}

void logic::EntityManager::setDefendersSize(int n)
{
	if (n <= allocatedDefenders)
	{
		defendersSize = n;
	}
}

bool logic::EntityManager::allocateDefenders(int n)
{
	// Do not allocate if the number of defenders
	// is less, just update the defenders size.
	if (n <= allocatedDefenders)
	{
		setDefendersSize(n);
	}
	else
	{		// Allocate again.
		bool success = allocate(&defendersPool, n);

		if (success)
		{
			allocatedDefenders = n;
			setDefendersSize(n);
			initEntities(defendersPool, allocatedDefenders, logic::EntityType::DEFENSE);
			return true;
		}
		else
		{
			return false;
		}

	}

	return true;
}

bool logic::EntityManager::allocatePlayer()
{
	if (playerPtr == nullptr)
	{
		playerPtr = new Entity(logic::EntityType::PLAYER);

		if (playerPtr == nullptr) return false;
	}

	return true;
}

bool logic::EntityManager::allocate(logic::Entity** poolPtr, int n)
{
	if (*poolPtr != nullptr)
	{
		delete[] *poolPtr;
		*poolPtr = nullptr;
	}

	*poolPtr = new Entity[n];

	return *poolPtr == nullptr ? false : true;
}

void logic::EntityManager::initEntities(logic::Entity* poolPtr, int n, logic::EntityType type)
{
	if (poolPtr != nullptr)
	{
		for (int i = 0; i < n; ++i)
		{
			poolPtr[i].init(type);
		}
	}
}

void logic::EntityManager::restartEntities(logic::EntityType type)
{
	switch (type)
	{
		case logic::EntityType::ATTACK:
			initEntities(attackersPool, attackersSize, type); break;
		case logic::EntityType::DEFENSE:
			initEntities(defendersPool, defendersSize, type); break;
		case logic::EntityType::PLAYER:
			playerPtr->init(logic::EntityType::PLAYER);
		default: break;
	}
}

void logic::EntityManager::updateAttackers(logic::Board& board, const std::vector<Point> &sp)
{
	/* Updating is done in two parts:
		For each attacker still alive:
		1. Check for nearby towers in all four directions.
			If a tower is found, decrease the life of the attacker.
		2. Move the attacker to the next tile, based on the shortest path.
	*/

	for (int i = 0; i < attackersSize; i++)
	{
		if (attackersPool[i].getHealth() <= 0) continue;

		Point currentPos = attackersPool[i].getPosition();

		Point periph[4];

		periph[0].x = currentPos.x;
		periph[0].y = currentPos.y - 1;

		periph[1].x = currentPos.x - 1;
		periph[1].y = currentPos.y;

		periph[2].x = currentPos.x + 1;
		periph[2].y = currentPos.y;

		periph[3].x = currentPos.x;
		periph[3].y = currentPos.y + 1;

		for (int h = 0; h < 4; h++)
		{
			const std::vector<logic::Entity*>* entities = nullptr;

			entities = board.getEntitiesAt(periph[h].x, periph[h].y);

			if (entities == nullptr) continue;

			if(entities->size() > 0)
			{
				if ((*entities)[0]->getType() == logic::EntityType::DEFENSE)
				{
					attackersPool[i].setHealth(
						attackersPool[i].getHealth() - (*entities)[0]->getAttackPower());
				}
			}

		}

		if (defendersPool[i].getHealth() < 0)
		{
			board.removeEntityAt(&defendersPool[i], currentPos.x, currentPos.y);
			continue;
		}

		for (std::size_t j = 0; j < sp.size(); j++)
		{
			if (currentPos == sp[j])
			{
				// Check if the position is next to the player tower.
				if (j == sp.size() - 2)
				{
					// Don't move the attacker to the player position
					// but kill the attacker and update the tower health.

					playerPtr->setHealth(playerPtr->getHealth()
					 - attackersPool[i].getAttackPower());

					attackersPool[i].setHealth(0);
					board.removeEntityAt(&attackersPool[i], currentPos.x, currentPos.y);
				}
				else
				{
					board.moveEntityTo(&attackersPool[i], sp[j + 1].x, sp[j + 1].y);
				}
			}
		}
	}

	// Introduce a new attacker in the next tick.
	setAttackersSize(attackersSize + 1);
}

void logic::EntityManager::placeDefendersOnBoard(logic::Board& board, std::vector<bool> &crom)
{
	int count = 0;

	for (unsigned int i = 0; i < crom.size(); i++)
	{
		if (crom[i] == 0) continue;

		int x = i % BOARD_W;
		int y = i / BOARD_H;

		defendersPool[count].setPosition(x, y);

		board.moveEntityTo(&defendersPool[count], x, y);

		count++;
	}

	setDefendersSize(count);
}

const logic::Entity* logic::EntityManager::getPlayer()
{
	return playerPtr;
}

int logic::EntityManager::getNumberOfAttackers()
{
	int count = 0;

	for (int i = 0; i < attackersSize; i++)
	{
		if (attackersPool[i].getHealth() > 0)
		{
			count++;
		}
	}

	return count;
}

int logic::EntityManager::getNumberOfTowers()
{
	return defendersSize;
}

logic::EntityManager::~EntityManager()
{
	delete[] attackersPool;
	delete[] defendersPool;

	delete playerPtr;

	attackersPool = nullptr;
	defendersPool = nullptr;
	playerPtr = nullptr;
}