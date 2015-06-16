#ifndef _GENETIC_HPP_
#define _GENETIC_HPP_

#include "defines.hpp"
#include "Game.hpp"

namespace ai
{
	class Genetic;

	struct Individual
	{
		std::vector<bool> chromosome;
		double fitness;

		Individual()
		{
			chromosome.reserve(100);
			fitness = 0;
		}
	};
}

class ai::Genetic
{
	// Private
	ai::Individual population[POPULATION_SIZE];

	logic::Game *gameInstance;

	// Performs selection among the chromosome in the population and returns the selected one.
	ai::Individual& selection();

	// Takes two parents and a vector, which will hold the children that result from the crossover.
	void crossover(ai::Individual &parent1, ai::Individual &parent2, std::vector<ai::Individual> &children);

	void mutation(ai::Individual &ind, double mutationProbability);

public:
	
	Genetic(logic::Game *gameInstance);

	void run();

	const ai::Individual *getPopulation();
};


#endif