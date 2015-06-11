#ifndef _GENETIC_HPP_
#define _GENETIC_HPP_

#include "defines.hpp"
#include "Game.hpp"

namespace ai
{
	class Genetic;

	struct Individual
	{
		std::vector<bool> cromosome;
		double fitness;

		Individual()
		{
			cromosome.reserve(100);
			fitness = 0;
		}
	};
}

class ai::Genetic
{
	// Private
	ai::Individual population[POPULATION_SIZE];

	logic::Game *gameInstance;

	// The summation of the fitness of all the individuals of the population.
	double fitSum;

public:
	
	Genetic(logic::Game *gameInstance);

	const ai::Individual *getPopulation();
};


#endif