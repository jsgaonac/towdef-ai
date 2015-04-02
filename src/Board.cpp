#include "Board.h"

const std::vector<logic::GameEntity*>* logic::Board::getEntityOn(uint8_t x, uint8_t y)
{
	if (x >= BOARD_W || y >= BOARD_H) return nullptr;

	return &board[x][y];
}