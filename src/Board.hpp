#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <cstdint>

#include "defines.hpp"
#include "Entity.hpp"

namespace logic
{
	class Board;
}

class logic::Board
{
	//Private:

	// The map is a grid of size GRID_W x GRID_H.
	std::vector<logic::Entity*> board[BOARD_W][BOARD_H];

	// Returns true if coordinates exist.
	bool isCoordValid(int x, int y) const;


public:

	Board();

	void removeEntityAt(logic::Entity* ent, int x, int y);

	// Returns true if the entity can move to position dst.
	// It also removes the entity from it previous position.
	bool moveEntityTo(Entity* ent, int dstX, int dstY);

	// Initializes player position.
	bool setPlayerAt(logic::Entity* player, int x, int y);

	// Returns a vector of entities, at the position (x, y) of the board.
	const std::vector<logic::Entity*>* getEntitiesAt(int x, int y) const;

	void reset();
};


#endif //_BOARD_H_