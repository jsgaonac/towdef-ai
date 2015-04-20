#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "GraphicalUI.hpp"

int main()
{
    ui::UI* uiInstance = new ui::GraphicalUI;
    logic::Game gameInstance(uiInstance);
    
    gameInstance.run();

    delete uiInstance;
    
    return 0;
}