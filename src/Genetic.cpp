#include "Genetic.hpp"
#include "Util.hpp"

ui::Genetic::Genetic(logic::Game *game)
{
	gameInstance = game;

	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		generateRandomCrom(population[i].cromosome, 100);
		population[i].fitness = gameInstance->run(population[i].cromosome, GAME_SPEED);
	}
}