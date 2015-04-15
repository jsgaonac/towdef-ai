#ifndef _ENTITY_MANAGER_H_
#define _ENTITY_MANAGER_H_

#include "Entity.hpp"

#include <cstring>

namespace logic
{
	EntityManager;
}

class logic::EntityManager
{
	//Private

	// The player is an entity so it it managed by this class.
	logic::Entity* player;
	
	// It is convenient to differentiate between
	// attack and defense entities.
	// Both are dynamically allocated.
	logic::Entity* attackersPool;
	logic::Entity* defendersPool;

	std::size_t attackersSize;
	std::size_t defendersSize;

	void initEntities(logic::Entity* poolPtr, std::size_t n, logic::EntityType type);

	// DELETES the previously allocated memory and allocates new of size n.
	bool allocate(logic::Entity* poolPtr, std::size_t n);

public:

	EntityManager();

	// Returns true if the n entities could be allocated.
	bool allocateAttackers(std::size_t n);
	bool allocateDefenders(std::size_t n);

	~EntityManager();

};


#endif //_ENTITY_MANAGER_H_