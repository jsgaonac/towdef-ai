#include "GraphicalUI.hpp"
#include "defines.hpp"

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

void ui::GraphicalUI::drawBoard()
{
    float lineThickness = 2;

    sf::RectangleShape lineH(sf::Vector2f(WINDOW_W, lineThickness));
    sf::RectangleShape lineV(sf::Vector2f(lineThickness, WINDOW_H));

    lineH.setFillColor(sf::Color::Black);
    lineV.setFillColor(sf::Color::Black);

    renderWindow.clear(sf::Color::White);

    // The space between each horizontal and vertical line.
    float lineHSpace = WINDOW_H / BOARD_H;
    float lineVSpace = WINDOW_W / BOARD_W;

    for (float i = lineHSpace; i <= WINDOW_H; i += lineHSpace)
    {
        renderWindow.draw(lineH);
        lineH.setPosition(0, i);
    }

    for (float i = lineVSpace; i <= WINDOW_W; i += lineVSpace)
    {
        renderWindow.draw(lineV);
        lineV.setPosition(i, 0);
    }

    lineH.setPosition(0, WINDOW_H - lineThickness);
    renderWindow.draw(lineH);
    
    lineV.setPosition(WINDOW_W - lineThickness, 0);
    renderWindow.draw(lineV);
    
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

        // We execute the game loop from the logic part of the game.
        if (!(gameInstance->*loopMethod)())
        {
            renderWindow.close();
        }

        // draw everything here...

        drawBoard();

        // end the current frame
        renderWindow.display();
    }
}
