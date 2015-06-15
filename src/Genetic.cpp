#include "Genetic.hpp"
#include "Util.hpp"

#include <iostream>

ai::Genetic::Genetic(logic::Game *game)
{
	gameInstance = game;
	
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		generateRandomCrom(population[i].cromosome, 100);
		population[i].fitness = gameInstance->run(population[i].cromosome, 0);
	}
}

void ai::Genetic::run()
{
	
}

ai::Individual& ai::Genetic::selection()
{
	/* Rank-selection (steps):
	// 1. Two cromosomes are chosen randomly.
	// 2. Each cromosome is given a probability (proportionally to their fitness) to be chosen.
	// 3. A random number R [0, 1] is generated.
	// 4. A cromosome is chosen.
	*/

	int first = 0;
	int second = 0;

	while (first == second)
	{
		first = getRandomInteger(0, POPULATION_SIZE - 1);
		second = getRandomInteger(0, POPULATION_SIZE - 1);
	}

	Individual &crom1 = population[first];
	Individual &crom2 = population[second];

	std::cout << crom1.fitness << " -- " << crom2.fitness << std::endl;

	double fitSum = crom1.fitness + crom2.fitness;

	double prob1 = crom1.fitness / fitSum;
	
	double r = getRandomReal(0, 1);

	if (r <= prob1)
	{
		return crom1;
	}

	return crom2;
}

const ai::Individual* ai::Genetic::getPopulation()
{
	return population;
}