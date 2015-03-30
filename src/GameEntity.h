#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

#include <cstdint>

namespace logic
{
	class GameEntity;
	enum class EntityType
	{
		STANDING,
		PRIVATE,
		BOMBER,
		FAST
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