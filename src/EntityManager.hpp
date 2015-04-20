#ifndef _ENTITY_MANAGER_H_
#define _ENTITY_MANAGER_H_

#include "Entity.hpp"

#include <cstring>

namespace logic
{
	class EntityManager;
}

class logic::EntityManager
{
	//Private

	// The player is an entity so it it managed by this class.
	logic::Entity* playerPtr;
	
	// It is convenient to differentiate between
	// attack and defense entities.
	// Both are dynamically allocated.
	logic::Entity* attackersPool;
	logic::Entity* defendersPool;

	// Number of allocated resources.
	std::size_t allocatedAttackers;
	std::size_t allocatedDefenders;

	// Number of used resources.
	std::size_t attackersSize;
	std::size_t defendersSize;

	void initEntities(logic::Entity* poolPtr, std::size_t n, logic::EntityType type);

	// DELETES the previously allocated memory and allocates new of size n.
	bool allocate(logic::Entity* poolPtr, std::size_t n);

public:

	EntityManager();

	// Allocates space for the n entities and initalizes all of them.
	// Returns true on succes.
	bool allocateAttackers(std::size_t n);
	bool allocateDefenders(std::size_t n);

	// Sets the maximum of available entities. We may allocate 100 entities and
	// make only 50 of them available with these methods.
	void setAttackersSize(std::size_t n);
	void setDefendersSize(std::size_t n);

	// This does not deallocate the memory if already allocated.
	// Returns true if could allocate or if already allocated.
	// False if error on allocation.
	bool allocatePlayer();

	// Re-init all the entities of the type to their default values.
	void restartEntities(logic::EntityType type);

	~EntityManager();

};


#endif //_ENTITY_MANAGER_H_