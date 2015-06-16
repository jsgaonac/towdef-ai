#include "TextUI.hpp"
#include "defines.hpp"

#include <iostream>

ui::TextUI::TextUI()
{
	
}

void ui::TextUI::create(int w, int h, int bpp)
{
	// Do nothing.
}

void ui::TextUI::show(logic::Game* gameInstance)
{
	// Run the game loop until the game is over.
	while ((gameInstance->*loopMethod)())
	{}
}

double ui::TextUI::showGeneticStats()
{
	const ai::Individual *population = geneticPtr->getPopulation();

	double fitSum = 0;
	double best = 0;
	double worst = 1;

	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		fitSum += population[i].fitness;

		if (population[i].fitness > best)
		{
			best = population[i].fitness;
		}

		if (population[i].fitness < worst)
		{
			worst = population[i].fitness;
		}
	}

	std::cout << "Average: " << fitSum / POPULATION_SIZE << std::endl;
	std::cout << "Best: " << best << " -- Worst: " << worst << std::endl;

	return fitSum / POPULATION_SIZE;
}