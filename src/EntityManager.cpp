#include "EntityManager.hpp"

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
			setAttackersSize(n);
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

void logic::EntityManager::updateAttackers(logic::Board& board)
{
	

}

void logic::EntityManager::placeDefendersOnBoard(logic::Board& board, std::vector<bool>& crom)
{
	int count = 0;

	for (unsigned int i = 0; i < crom.size(); i++)
	{
		if (crom[i] == 0) continue;

		int x = i % BOARD_W;
		int y = i / BOARD_H;

		defendersPool[count].setPos(x, y);

		board.moveEntityTo(&defendersPool[count], x, y);

		count++;
	}
}

const logic::Entity* logic::EntityManager::getPlayer()
{
	return playerPtr;
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