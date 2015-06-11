#include "GraphicalUI.hpp"
#include "defines.hpp"
#include "Board.hpp"
#include "Game.hpp"

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

    if (!attackers.loadAndSetTexture("../assets/attackers.png"))
    {
        std::cout << "No se pudo cargar attackers.png!" << std::endl;
    }

    if (!defenders.loadAndSetTexture("../assets/defenders.png"))
    {
        std::cout << "No se pudo cargar defenders.png!" << std::endl;
    }

    float scaleFactor = 0.5;
    
    // We multiply by a constant factor to make it a little bit smaller.
    float scaleX = (1 / (respawn.texture.getSize().x / GRID_W)) * scaleFactor;
    float scaleY = (1 / (respawn.texture.getSize().y / GRID_H)) * scaleFactor;

    respawn.sprite.scale(scaleX, scaleY);

    // We center the sprite.
    respawn.sprite.setPosition(
        (GRID_W - respawn.texture.getSize().x * scaleX) * 0.5,
        (GRID_H - respawn.texture.getSize().y * scaleY) * 0.5
        );

    // We multiply by a constant factor to make it a little bit smaller.
    scaleX = (1 / (tower.texture.getSize().x / GRID_W)) * scaleFactor;
    scaleY = (1 / (tower.texture.getSize().y / GRID_H)) * scaleFactor;

    tower.sprite.scale(scaleX, scaleY);

    tower.sprite.setPosition(
        WINDOW_W - (GRID_W + tower.texture.getSize().x * scaleX) * 0.5,
        WINDOW_H - (GRID_H + tower.texture.getSize().y * scaleY) * 0.5
        );

    scaleX = (1 / (attackers.texture.getSize().x / GRID_W)) * scaleFactor;
    scaleY = (1 / (attackers.texture.getSize().y / GRID_H)) * scaleFactor;

    attackers.sprite.scale(scaleX, scaleY);


    scaleX = (1 / (defenders.texture.getSize().x / GRID_W)) * scaleFactor;
    scaleY = (1 / (defenders.texture.getSize().y / GRID_H)) * scaleFactor;

    defenders.sprite.scale(scaleX, scaleY);
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
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Q)
                {
                    renderWindow.close();
                }
            }
        }

        // We execute the game loop from the logic part of the game.
        if (!(gameInstance->*loopMethod)())
        {
            renderWindow.close();
        }

        // draw everything here...

        drawBoard();
        drawEntities(gameInstance);

        // end the current frame
        renderWindow.display();
    }

    windowExists = false;
}

void ui::GraphicalUI::drawEntities(logic::Game* gameInstance)
{
    sf::Vector2f attScale = attackers.sprite.getScale();
    
    sf::Vector2f defScale = attackers.sprite.getScale();

    const logic::Board& board = gameInstance->getBoard();

    for (int i = 0; i < BOARD_W; i++)
    {
        for (int j = 0; j < BOARD_H; j++)
        {
            const std::vector<logic::Entity*>* entities = board.getEntitiesAt(i, j);

            if (entities == nullptr) continue;

            if (entities->size() != 0)
            {
                if ((*entities)[0]->getType() == logic::EntityType::ATTACK)
                {
                    if ((*entities)[0]->getHealth() > 0)
                    {
                        attackers.sprite.setPosition(
                            (i * GRID_W) + (GRID_W - attackers.texture.getSize().x * attScale.x) * 0.5,
                            (j * GRID_H) + (GRID_H - attackers.texture.getSize().y * attScale.y) * 0.5
                            );

                        renderWindow.draw(attackers.sprite);
                    }
                }
                else if ((*entities)[0]->getType() == logic::EntityType::DEFENSE)
                {
                    defenders.sprite.setPosition(
                        (i * GRID_W) + (GRID_W - defenders.texture.getSize().x * defScale.x) * 0.5,
                        (j * GRID_H) + (GRID_H - defenders.texture.getSize().y * defScale.y) * 0.5
                        );

                    renderWindow.draw(defenders.sprite);
                }
            }
        }
    }
}



