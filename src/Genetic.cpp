#include "Genetic.hpp"
#include "Util.hpp"

#include <iostream>

#define GAME_SPEED 0
#define MUT_PROB 0.01

ai::Genetic::Genetic(logic::Game *game, ui::UI *uiPtr)
{
	gameInstance = game;
	ui = uiPtr;
	
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		generateRandomCrom(population[i].chromosome, CHROM_LENGTH);
		population[i].fitness = gameInstance->run(population[i].chromosome, GAME_SPEED);
	}
}

void ai::Genetic::run()
{
	int iterations = 0;
	double avg = 0;

	while (iterations < 20000 && avg < 0.99)
	{
		ai::Individual &parent1 = selection();
		ai::Individual &parent2 = selection();

		std::vector<ai::Individual> children;

		crossover(parent1, parent2, children);

		mutation(children[0], MUT_PROB);
		mutation(children[1], MUT_PROB);

		children[0].fitness = gameInstance->run(children[0].chromosome, GAME_SPEED);
		children[1].fitness = gameInstance->run(children[1].chromosome, GAME_SPEED);

		replacement(children[0]);
		replacement(children[1]);

		iterations++;

		avg = ui->showGeneticStats();
	}

	ui->showGeneticStats();
}

ai::Individual& ai::Genetic::selection()
{
	/* Rank-selection (steps):
	// 1. Two chromosomes are chosen randomly.
	// 2. Each chromosome is given a probability (proportionally to their fitness) to be chosen.
	// 3. A random number R [0, 1] is generated.
	// 4. A chromosome is chosen.
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

	double fitSum = crom1.fitness + crom2.fitness;

	double prob1 = crom1.fitness / fitSum;
	
	double r = getRandomReal(0, 1);

	if (r < prob1)
	{
		return crom1;
	}

	return crom2;
}

void ai::Genetic::crossover(ai::Individual &parent1, ai::Individual &parent2, std::vector<ai::Individual> &children)
{
	/* Uniform crossover is performed.
	// a random binary mask is generated of the same size of the cromosome
	// for each gen i, if the ith value of the mask is 1, the first child will
	// copy its ith gene from his first parent, and the second child from his second
	// parent. Otherwise if the ith value of the mask is 0.
	*/

	std::vector<bool> mask;
	generateRandomCrom(mask, CHROM_LENGTH);

	ai::Individual child1;
	ai::Individual child2;

	children.push_back(child1);
	children.push_back(child2);

	for (std::size_t i = 0; i < CHROM_LENGTH; i++)
	{
		if (mask[i] == 1)
		{
			children[0].chromosome.push_back(parent1.chromosome[i]);
			children[1].chromosome.push_back(parent2.chromosome[i]);
		}
		else
		{
			children[0].chromosome.push_back(parent2.chromosome[i]);
			children[1].chromosome.push_back(parent1.chromosome[i]);
		}
	}
}

void ai::Genetic::mutation(ai::Individual &ind, double mutationProbability)
{
	for (std::size_t i = 0; i < ind.chromosome.size(); i++)
	{
		double z = getRandomReal(0, 1);

		if (z <= mutationProbability)
		{
			// Value is fliiped.
			ind.chromosome[i] = !ind.chromosome[i];
		}
	}
}

void ai::Genetic::replacement(ai::Individual &ind)
{
	int randIndex = getRandomInteger(0, POPULATION_SIZE - 1);

	if (population[randIndex].fitness < ind.fitness)
	{
		population[randIndex].chromosome = ind.chromosome;
		population[randIndex].fitness = ind.fitness;
	}
}

const ai::Individual* ai::Genetic::getPopulation()
{
	return population;
}