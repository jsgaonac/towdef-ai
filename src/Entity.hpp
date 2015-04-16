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

public:

	Entity();
	Entity(logic::EntityType type);
	
	int getHealth();
	int getAttackPower();
	int getSpeed();

	void init(logic::EntityType type);

};

#endif //_GAME_ENTITY_H_