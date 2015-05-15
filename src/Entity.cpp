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

int logic::Entity::getHealth() const
{
	return health;
}

int logic::Entity::getAttackPower() const
{
	return attackPower;
}

int logic::Entity::getSpeed() const
{
	return speed;
}

int logic::Entity::getPosX() const
{
	return posX;
}

int logic::Entity::getPosY() const
{
	return posY;
}

void logic::Entity::setPos(int x, int y)
{
	posX = x;
	posY = y;
}

logic::EntityType logic::Entity::getType() const
{
	return type;
}

void logic::Entity::init(logic::EntityType type)
{
	this->type = type;
	
	switch (type)
	{
		case logic::EntityType::ATTACK:
		{
			health = ATTACK_HEALTH;
			attackPower = ATTACK_POWER;
			speed = ATTACK_SPEED;
			
			posX = RESPAWN_X;
			posY = RESPAWN_Y;
			break;
		}
		case logic::EntityType::DEFENSE:
		{
			health = DEFENSE_HEALTH;
			attackPower = DEFENSE_POWER;
			speed = DEFENSE_SPEED;

			posX = -1;
			posY = -1;
			break;
		}
		case logic::EntityType::PLAYER:
		{
			health = PLAYER_HEALTH;
			attackPower = PLAYER_POWER;
			speed = PLAYER_SPEED;

			posX = PLAYER_X;
			posY = PLAYER_Y;
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