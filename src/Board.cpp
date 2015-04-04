#include "Board.h"

logic::Board::Board()
{
	// Setting player position.


}

bool logic::Board::isCoordValid(uint8_t x, uint8_t y)
{
	if (x >= BOARD_W || y >= BOARD_H) return false;

	return true;
}

bool logic::Board::setPlayerAt(logic::GameEntity* player, uint8_t x, uint8_t y)
{
	if (!isCoordValid(x, y)) return false;

	board[x][y].push_back(player);
	
	return true;
}

bool logic::Board::moveEntity(GameEntity* ent, uint8_t srcX, uint8_t srcY, uint8_t dstX, uint8_t dstY)
{
	if (!isCoordValid(srcX, srcY) || !isCoordValid(dstX, dstY)) return false;

	if (!board[srcX][srcY].empty())
	{
		logic::EntityType type = board[srcX][srcY][0]->getType();

		// Moving entities can occupy tiles with non-standing entities only.
		if (type == logic::EntityType::STANDING || type == logic::EntityType::PLAYER)
		{
			return false;
		}
	}

	// The entity is added if the tile is empty or if the entities in the tile are movable.
	board[dstX][dstY].push_back(ent);
	
	return true;
}

const std::vector<logic::GameEntity*>* logic::Board::getEntitiesAt(uint8_t x, uint8_t y)
{
	if (!isCoordValid(x, y)) return nullptr;

	return &board[x][y];
}