#include "GraphicalUI.hpp"
#include "defines.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>


ui::GraphicalUI::GraphicalUI()
{
	windowExists = false;

    if (!respawn.loadAndSetTexture("../assets/respawn.png"))
    {
        std::cout << "No se pudo cargar respawn.png!" << std::endl;
    }

    if (!tower.loadAndSetTexture("../assets/tower.png"))
    {
        std::cout << "No se pudo cargar tower.png!" << std::endl;
    }

    float gridH = WINDOW_H / BOARD_H;
    float gridW = WINDOW_W / BOARD_W;

    float scaleFactor = 0.5;
    
    // We multiply by a constant factor to make it a little bit smaller.
    float scaleX = (1 / (respawn.texture.getSize().x / gridW)) * scaleFactor;
    float scaleY = (1 / (respawn.texture.getSize().y / gridH)) * scaleFactor;

    respawn.sprite.scale(scaleX, scaleY);

    // We center the sprite.
    respawn.sprite.setPosition(
        (gridW - respawn.texture.getSize().x * scaleX) * 0.5,
        (gridH - respawn.texture.getSize().y * scaleY) * 0.5
        );

    // We multiply by a constant factor to make it a little bit smaller.
    scaleX = (1 / (tower.texture.getSize().x / gridW)) * scaleFactor;
    scaleY = (1 / (tower.texture.getSize().y / gridH)) * scaleFactor;

    tower.sprite.scale(scaleX, scaleY);

    tower.sprite.setPosition(
        WINDOW_W - (gridW + tower.texture.getSize().x * scaleX) * 0.5,
        WINDOW_H - (gridH + tower.texture.getSize().y * scaleY) * 0.5
        );
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
    float lineThickness = 1.5;

    sf::RectangleShape lineH(sf::Vector2f(WINDOW_W, lineThickness));
    sf::RectangleShape lineV(sf::Vector2f(lineThickness, WINDOW_H));

    lineH.setFillColor(sf::Color::Black);
    lineV.setFillColor(sf::Color::Black);

    renderWindow.clear(sf::Color(229, 229, 229));

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

    renderWindow.draw(respawn.sprite);
    renderWindow.draw(tower.sprite);
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
