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
	std::vector<logic::GameEntity*> board[BOARD_W][BOARD_H];

	// Returns true if coordinates exist.
	bool isCoordValid(uint8_t x, uint8_t y);

public:

	Board();

	// Returns true if the entity at src can move to position dst.
	bool moveEntityTo(GameEntity* ent, uint8_t srcX, uint8_t srcY, uint8_t dstX, uint8_t dstY);

	// Initializes player position.
	bool setPlayerAt(logic::GameEntity* player, uint8_t x, uint8_t y);

	// Returns a vector of entities, at the position (x, y) of the board.
	const std::vector<logic::GameEntity*>* getEntitiesAt(uint8_t x, uint8_t y);
};


#endif //_BOARD_H_