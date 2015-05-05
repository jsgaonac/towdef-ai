#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "GraphicalUI.hpp"

int main()
{
    ui::UI* uiInstance = new ui::GraphicalUI;
    logic::Game gameInstance(uiInstance);

    std::vector<bool> gen = {0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0 , 1, 0, 1, 1, 1, 1, 0, 1};
    
    gameInstance.run(gen);

    delete uiInstance;
    
    return 0;
}