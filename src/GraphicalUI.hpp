#ifndef _GRAPHICAL_UI_HPP_
#define _GRAPHICAL_UI_HPP_

#include <SFML/Graphics.hpp>

#include "UI.hpp"

#include <string>

namespace ui
{
	class GraphicalUI;
	struct Sprite
	{
		sf::Sprite sprite;
		sf::Texture texture;

		bool loadAndSetTexture(std::string filename)
		{
			bool ret = texture.loadFromFile(filename);

			sprite.setTexture(texture);
			texture.setSmooth(true);

			return ret;
		}	
	};
}

class ui::GraphicalUI : public ui::UI
{
	sf::RenderWindow renderWindow;

	ui::Sprite respawn;
	ui::Sprite tower;

	ui::Sprite attackers;
	ui::Sprite defenders;

	void drawBoard();

	void drawEntities(logic::Game *gameInstance);

	bool windowExists;

public:

	GraphicalUI();

	void create(int w, int h, int bpp = 32) override;
	void show(logic::Game* gameInstance) override;
};

#endif