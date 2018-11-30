#pragma once
#include "CKnapsackProblem.h"
#include "CIndividual.h"

class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm(int iPopulationSize, double dMutationProb, double dCrossProb,CKnapsackProblem * c_knapsack_problem);
	~CGeneticAlgorithm();

	double dGetMutationProb();
	double dGetCrossProb();
	
private:
	int i_population_size;
	double d_mutation_prob;
	double d_cross_prob;
	//int i_stop_iteration;

	CIndividual ** c_tab_population;
	CIndividual * c_best_individual;
	CKnapsackProblem * c_knapsack_problem;
};

