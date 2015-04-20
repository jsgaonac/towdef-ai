#include "GraphicalUI.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

ui::GraphicalUI::GraphicalUI()
{
	windowExists = false;
}

void ui::GraphicalUI::create(int w, int h, int bpp)
{
	if (!windowExists)
	{
		renderWindow.create(sf::VideoMode(w, h, bpp), "TowDef-AI");
		windowExists = true;
	}
}

void ui::GraphicalUI::show(logic::Game* gameInstance)
{
	if (loopMethod == nullptr)
	{
		std::cout << "ui::show()==> No se establecio ningun metodo a ejecutar." << std::endl;
		return;
	}

	while (renderWindow.isOpen())
    {
        // check all the renderWindow's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            // "close requested" event: we close the renderWindow
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }

        // clear the renderWindow with black color
        renderWindow.clear(sf::Color::White);

        // We execute the game loop from the logic part of the game.
        if (!(gameInstance->*loopMethod)())
        {
            renderWindow.close();
        }

        // draw everything here...
        // renderWindow.draw(...);

        // end the current frame
        renderWindow.display();
    }
}
