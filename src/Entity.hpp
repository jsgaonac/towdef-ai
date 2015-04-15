#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

#include <cstdint>

namespace logic
{
	class GameEntity;

	/* Type explanation:
		-- STANDING and TOWER:
			These are the entites that the player uses.
			The standing entities are the ones that defend the player
			against the attackers. The tower is the entity to defend.

		-- PRIVATE, BOMBER and FAST:
			Attacking entities. The player should defend his tower from these.
			They differ in health, speed and attack power.
	*/

	enum class EntityType
	{
		STANDING,
		PRIVATE,
		BOMBER,
		FAST,
		TOWER
	};
}

class logic::GameEntity
{
	// Private:
	uint32_t health;
	uint32_t attackPower;
	uint32_t speed;

	// The type determines the attack power and health.
	logic::EntityType type;

public:

	GameEntity();
	GameEntity(logic::EntityType type);

	uint32_t getHealth();
	logic::EntityType getType();
};

#endif //_GAME_ENTITY_H_