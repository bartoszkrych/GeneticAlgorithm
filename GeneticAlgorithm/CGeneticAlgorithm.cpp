#include "CGeneticAlgorithm.h"
#include <cstddef>


CGeneticAlgorithm::CGeneticAlgorithm(int iPopulationSize, double dMutationProb, double dCrossProb,CKnapsackProblem *cKnapsack)
{
	i_population_size = iPopulationSize;
	d_mutation_prob = dMutationProb;
	d_cross_prob = dCrossProb;
	//i_stop_iteration = iStopIteration;
	c_knapsack_problem = cKnapsack;
	c_tab_population = new CIndividual*[i_population_size];
	for (int i = 0; i < i_population_size; i++)
	{
		c_tab_population[i] = new CIndividual(c_knapsack_problem);
	}
	c_best_individual = c_tab_population[0];
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

