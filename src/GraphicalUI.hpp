#ifndef _GRAPHICAL_UI_HPP_
#define _GRAPHICAL_UI_HPP_

#include <SFML/Graphics.hpp>

#include "UI.hpp"

namespace ui
{
	class GraphicalUI;
}

class ui::GraphicalUI : public ui::UI
{
	sf::RenderWindow renderWindow;

	void drawBoard();

	bool windowExists;

public:

	GraphicalUI();

	void create(int w, int h, int bpp = 32) override;
	void show(logic::Game* gameInstance) override;
};

#endif