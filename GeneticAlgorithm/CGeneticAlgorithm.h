#pragma once
#include "CKnapsackProblem.h"
#include "CIndividual.h"

class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm(int iPopulationSize, double dMutationProb, double dCrossProb, int iStopIteration);
	~CGeneticAlgorithm();

	static double dGetMutationProb();
	static double dGetCrossProb();
	
private:
	int i_population_size;
	static double d_mutation_prob;
	static double d_cross_prob;
	int i_stop_iteration;

	CIndividual * c_best_individual;
};

