#include "Board.hpp"

logic::Board::Board()
{
	
}

bool logic::Board::isCoordValid(int x, int y) const
{
	if (x >= BOARD_W || y >= BOARD_H) return false;
	if (x < 0 || y < 0) return false;

	return true;
}

bool logic::Board::setPlayerAt(logic::Entity* player, int x, int y)
{
	if (!isCoordValid(x, y)) return false;

	board[x][y].push_back(player);
	
	return true;
}

bool logic::Board::moveEntityTo(Entity* ent, int dstX, int dstY)
{
	int srcX = ent->getPosition().x;
	int srcY = ent->getPosition().y;

	removeEntityAt(ent, srcX, srcY);

	// The coordinate must be a valid one.
	if (!isCoordValid(dstX, dstY)) return false;

	// In case the coordinate is occupied, check the type of the Entity occupying that place.
	if (!board[dstX][dstY].empty())
	{
		logic::EntityType type = board[dstX][dstY][0]->getType();

		// Only attacking entities can be in a same position.
		if (type != logic::EntityType::ATTACK)
		{
			return false;
		}
	}

	// The entity is added if the tile is empty or if the entities in the tile are attackers.
	board[dstX][dstY].push_back(ent);

	// Update the new position of the entity.
	ent->setPosition(dstX, dstY);

	return true;
}

void logic::Board::removeEntityAt(logic::Entity* ent, int x, int y)
{
	std::size_t size = board[x][y].size();

	for (std::size_t i = 0; i < size; ++i)
	{
		if (board[x][y][i] == ent)
		{
			board[x][y][i] = board[x][y][size - 1];
			board[x][y].pop_back();
			break;
		}
	}
}

const std::vector<logic::Entity*>* logic::Board::getEntitiesAt(int x, int y) const
{
	if (!isCoordValid(x, y)) return nullptr;

	return &board[x][y];
}