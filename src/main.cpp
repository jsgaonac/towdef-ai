#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "GraphicalUI.hpp"
#include "Util.hpp"

int main()
{
    ui::UI* uiInstance = new ui::GraphicalUI;
    logic::Game gameInstance(uiInstance);

    std::vector<bool> gen;

    generateRandomGen(gen, 100);
    
    gameInstance.run(gen);

    delete uiInstance;


    
    return 0;
}