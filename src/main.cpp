#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "GraphicalUI.hpp"
#include "TextUI.hpp"


int main()
{
    ui::UI* uiInstance = new ui::GraphicalUI;
    
    logic::Game gameInstance(uiInstance);

    ai::Genetic genetic(&gameInstance);

    uiInstance->setGenetic(&genetic);

    auto pop = genetic.getPopulation();

    for (int i = 0; i < POPULATION_SIZE; i++)
    {
    	std::cout << pop[i].fitness << std::endl;
    }

    delete uiInstance;
    
    return 0;
}