#include "EntityManager.hpp"

logic::EntityManager::EntityManager()
{
	attackersPool = nullptr;
	defendersPool = nullptr;
	playerPtr = nullptr;

	attackersSize = 0;
	defendersSize = 0;
}

bool logic::EntityManager::allocateAttackers(std::size_t n)
{
	// Do not allocate if the number of attackers
	// is less or equal, just update the attackers size.
	if (n <= allocatedAttackers)
	{
		setAttackersSize(n);
	}
	else
	{	// Allocate again.
		bool success = allocate(attackersPool, n);

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

void logic::EntityManager::setAttackersSize(std::size_t n)
{
	if (n <= allocatedAttackers)
	{
		attackersSize = n;
	}
}

void logic::EntityManager::setDefendersSize(std::size_t n)
{
	if (n <= allocatedDefenders)
	{
		defendersSize = n;
	}
}

bool logic::EntityManager::allocateDefenders(std::size_t n)
{
	// Do not allocate if the number of defenders
	// is less, just update the defenders size.
	if (n <= allocatedDefenders)
	{
		setDefendersSize(n);
	}
	else
	{		// Allocate again.
		bool success = allocate(defendersPool, n);

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

bool logic::EntityManager::allocate(logic::Entity* poolPtr, std::size_t n)
{
	if (poolPtr != nullptr)
	{
		delete[] poolPtr;
		poolPtr = nullptr;
	}

	poolPtr = new Entity[n];

	return poolPtr == nullptr ? false : true;
}

void logic::EntityManager::initEntities(logic::Entity* poolPtr, std::size_t n, logic::EntityType type)
{
	if (poolPtr != nullptr)
	{
		for (std::size_t i = 0; i < n; ++i)
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

logic::EntityManager::~EntityManager()
{
	delete[] attackersPool;
	delete[] defendersPool;

	delete playerPtr;

	attackersPool = nullptr;
	defendersPool = nullptr;
	playerPtr = nullptr;
}