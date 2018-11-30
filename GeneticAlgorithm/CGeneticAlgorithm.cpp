#include "CGeneticAlgorithm.h"
#include <cstddef>


CGeneticAlgorithm::CGeneticAlgorithm(int iPopulationSize, double dMutationProb, double dCrossProb, int iStopIteration)
{
	i_population_size = iPopulationSize;
	d_mutation_prob = dMutationProb;
	d_cross_prob = dCrossProb;
	i_stop_iteration = iStopIteration;
	c_best_individual = NULL;
}

CGeneticAlgorithm::~CGeneticAlgorithm()
{
}

double CGeneticAlgorithm::dGetMutationProb()
{
	return d_mutation_prob;
}

double CGeneticAlgorithm::dGetCrossProb()
{
	return d_cross_prob;
}
