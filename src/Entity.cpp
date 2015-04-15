#include "Entity.hpp"
#include "defines.hpp"

logic::Entity::Entity()
{
	Entity(logic::EntityType::NONE);	
}

logic::Entity::Entity(logic::EntityType type)
{
	init(type);
}

int logic::Entity::getHealth()
{
	return health;
}

int logic::Entity::getAttackPower()
{
	return attackPower;
}

int logic::Entity::getSpeed()
{
	return speed;
}

void logic::Entity::init(logic::EntityType type)
{
	switch (type)
	{
		case logic::EntityType::ATTACK:
		{
			health = ATTACK_HEALTH;
			attackPower = ATTACK_POWER;
			speed = ATTACK_SPEED;
			break;
		}
		case logic::EntityType::DEFENSE:
		{
			health = DEFENSE_HEALTH;
			attackPower = DEFENSE_POWER;
			speed = DEFENSE_SPEED;
			break;
		}
		case logic::EntityType::NONE:
		{
			health = 0;
			attackPower = 0;
			speed = 0;
			break;
		}
		default: break;
	}
}