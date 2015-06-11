#include "Genetic.hpp"
#include "Util.hpp"

ai::Genetic::Genetic(logic::Game *game)
{
	gameInstance = game;
	fitSum = 0;

	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		generateRandomCrom(population[i].cromosome, 100);
		population[i].fitness = gameInstance->run(population[i].cromosome, 300);
		fitSum += population[i].fitness;
	}
}

const ai::Individual* ai::Genetic::getPopulation()
{
	return population;
}