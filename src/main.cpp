#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "GraphicalUI.hpp"


int main()
{

    ui::UI* uiInstance = new ui::GraphicalUI;
    logic::Game gameInstance(uiInstance);

    delete uiInstance;
    
    return 0;
}