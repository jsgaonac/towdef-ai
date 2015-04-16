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
	if (n <= attackersSize)
	{
		attackersSize = n;
	}
	else
	{
		// Allocate again.
		attackersSize = n;
		bool success = allocate(attackersPool, attackersSize);
	}

	if (success)
	{
		initEntities(attackersPool, attackersSize, logic::EntityType::ATTACK);
		return true;
	}

	return false;
}

bool logic::EntityManager::allocateDefenders(std::size_t n)
{
	// Do not allocate if the number of defenders
	// is less, just update the defenders size.
	if (n <= defendersSize)
	{
		defendersSize = n;
	}
	else
	{
		// Allocate again.
		defendersSize = n;
		bool success = allocate(defendersPool, defendersSize);
	}

	if (success)
	{
		initEntities(defendersPool, defendersSize, logic::EntityType::DEFENSE);
		return true;
	}

	return false;
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
			poolPtr[i]->init(type);		
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
			player->init(logic::EntityType::PLAYER);
		default: break;
	}
}

logic::EntityManager::~EntityManager()
{
	delete[] attackers;
	delete[] defenders;

	delete playerPtr;

	attackers = nullptr;
	defenders = nullptr;
	playerPtr = nullptr;
}