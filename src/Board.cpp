#include "Board.hpp"

logic::Board::Board()
{
	// Setting player position.


}

bool logic::Board::isCoordValid(int x, int y)
{
	if (x >= BOARD_W || y >= BOARD_H) return false;

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
	int srcX = ent->getPosX();
	int srcY = ent->getPosY();

	// The coordinate must be a valid one.
	if (!isCoordValid(srcX, srcY) || !isCoordValid(dstX, dstY)) return false;

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
	ent->setPos(dstX, dstY);

	// Search and remove the entity from the previous position (vector).
	std::vector<Entity*> &previousPos = board[srcX][srcY];

	for (std::size_t i = 0; i < previousPos.size(); i++)
	{
		// If the moved entity was found, replace it with the last element in vector
		// and pop the last element.
		if (previousPos[i] == ent)
		{
			previousPos[i] = previousPos[previousPos.size() - 1];
			previousPos.pop_back();
			break;
		}		
	}
	
	return true;
}

const std::vector<logic::Entity*>* logic::Board::getEntitiesAt(int x, int y)
{
	if (!isCoordValid(x, y)) return nullptr;

	return &board[x][y];
}