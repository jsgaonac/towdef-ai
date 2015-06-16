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

    auto pop = genetic.getPopulation();

    uiInstance = new ui::GraphicalUI;

    gameInstance.setUI(uiInstance);

    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        gameInstance.run(pop[i].chromosome, 100);
    }

    delete uiInstance;    
    
    return 0;
}