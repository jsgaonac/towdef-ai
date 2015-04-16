#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

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
	
	int getHealth();
	int getAttackPower();
	int getSpeed();

	int getPosX();
	int getPosY();

	void setPos(int x, int y);

	logic::EntityType getType();

	void init(logic::EntityType type);

};

#endif //_GAME_ENTITY_H_