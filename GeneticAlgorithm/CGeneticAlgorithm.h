#pragma once
#include "CKnapsackProblem.h"
#include "CIndividual.h"

class CGeneticAlgorithm
{
public:
	CGeneticAlgorithm();
	CGeneticAlgorithm(int iPopulationSize, double dMutationProb, double dCrossProb,CKnapsackProblem * cKnapsackProblem);
	~CGeneticAlgorithm();

	bool bInitialObject(int iPopulationSize, double dMutationProb, double dCrossProb, CKnapsackProblem * cKnapsackProblem);
	void vStartAlgorithm(int iIter);
	void vGenerateNewPopulation();
	
private:
	bool bMatchBestIndividual(CIndividual* cToMatch);
	int iGenerateInteger(int iFrom, int iTo);
	double dGenerateDouble(double dFrom, double dTo);

	int i_population_size;
	double d_mutation_prob;
	double d_cross_prob;

	CIndividual ** ppc_tab_population;
	CIndividual * pc_best_individual;
	CKnapsackProblem * pc_knapsack_problem;
};

