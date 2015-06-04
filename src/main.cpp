#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "GraphicalUI.hpp"
#include "Util.hpp"

int main()
{
    ui::UI* uiInstance = new ui::GraphicalUI;
    logic::Game gameInstance(uiInstance);

    std::vector<bool> crom;

    generateRandomCrom(crom, 100);
    
    gameInstance.run(crom, 300);

    delete uiInstance;
    
    return 0;
}