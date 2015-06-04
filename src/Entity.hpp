#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

#include "Util.hpp"

namespace logic
{
	class Entity;

	enum class EntityType
	{
		DEFENSE,
		ATTACK,
		PLAYER,
		NONE
	};
}

class logic::Entity
{
	// Private:
	int health;
	int attackPower;
	int speed;

	// Coordinates relative to the Board where the entity is located.
	int posX;
	int posY;

	logic::EntityType type;

public:

	Entity();
	Entity(logic::EntityType type);
	
	int getHealth() const;
	int getAttackPower() const;
	int getSpeed() const;

	Point getPosition() const;

	void setPosition(int x, int y);

	void setHealth(int health);

	logic::EntityType getType() const;

	void init(logic::EntityType type);

};

#endif //_GAME_ENTITY_H_