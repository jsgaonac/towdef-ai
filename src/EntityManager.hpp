#ifndef _ENTITY_MANAGER_H_
#define _ENTITY_MANAGER_H_

#include "Entity.hpp"
#include "Board.hpp"

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
	int allocatedAttackers;
	int allocatedDefenders;

	// Number of used resources.
	int attackersSize;
	int defendersSize;

	void initEntities(logic::Entity* poolPtr, int n, logic::EntityType type);

	// DELETES the previously allocated memory and allocates new of size n.
	bool allocate(logic::Entity** poolPtr, int n);

public:

	EntityManager();

	// Allocates space for the n entities and initalizes all of them.
	// Returns true on succes.
	bool allocateAttackers(int n);
	bool allocateDefenders(int n);

	// Sets the maximum of available entities. We may allocate 100 entities and
	// make only 50 of them available with these methods.
	void setAttackersSize(int n);
	void setDefendersSize(int n);

	// This does not deallocate the memory if already allocated.
	// Returns true if could allocate or if already allocated.
	// False if error on allocation.
	bool allocatePlayer();

	const logic::Entity* getPlayer();

	// Re-init all the entities of the type to their default values.
	void restartEntities(logic::EntityType type);

	// Returns the number of not-dead attackers.
	int getNumberOfAttackers();

	// Tells the entities to update their state on the board.
	void updateAttackers(logic::Board& board, const std::vector<Point> &shortestPath);

	// Iterates through all the active defenders and puts them on the board.
	// This is needed to be called only once, since the defenders do not move.
	void placeDefendersOnBoard(logic::Board& board, std::vector<bool>& gen);

	~EntityManager();

};


#endif //_ENTITY_MANAGER_H_