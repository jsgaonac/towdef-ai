#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <cstdint>

#include "defines.h"
#include "GameEntity.h"

namespace logic
{
	class Board;
}

class logic::Board
{
	//Private:
	std::vector<logic::GameEntity*> board[BOARD_W][BOARD_H];

public:

	// Returns a vector of entities, at the position (x, y) of the board.
	const std::vector<logic::GameEntity*>* getEntityOn(uint8_t x, uint8_t y);
};


#endif //_BOARD_H_