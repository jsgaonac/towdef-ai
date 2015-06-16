#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "GraphicalUI.hpp"
#include "TextUI.hpp"


int main()
{
    ui::UI* uiInstance = new ui::TextUI;
    
    logic::Game gameInstance(uiInstance);

    ai::Genetic genetic(&gameInstance, uiInstance);

    uiInstance->setGenetic(&genetic);

    genetic.run();

    delete uiInstance;
    
    return 0;
}