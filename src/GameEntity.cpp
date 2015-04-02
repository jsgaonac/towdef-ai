#include "GameEntity.h"
#include "defines.h"

logic::GameEntity::GameEntity()
{
	GameEntity(logic::EntityType::STANDING);
}

logic::GameEntity::GameEntity(logic::EntityType type)
{
	this->type = type;

	switch(type)
	{
		case logic::EntityType::PRIVATE:
		{
			this->health = PRIVATE_HEALTH;
			this->attackPower = PRIVATE_ATTACK;
			this->speed = PRIVATE_SPEED;
			break;
		}
		case logic::EntityType::BOMBER:
		{
			this->health = BOMBER_HEALTH;
			this->attackPower = BOMBER_ATTACK;
			this->speed = BOMBER_SPEED;
			break;
		}
		case logic::EntityType::FAST:
		{
			this->health = FAST_HEALTH;
			this->attackPower = FAST_ATTACK;
			this->speed = FAST_SPEED;
			break;
		}
		case logic::EntityType::STANDING:
		{
			this->health = STANDING_HEALTH;
			this->attackPower = STANDING_ATTACK;
			this->speed = STANDING_SPEED;
			break;
		}
		default: break;
	}
}

uint32_t logic::GameEntity::getHealth()
{
	return health;
}

logic::EntityType logic::GameEntity::getType()
{
	return type;
}