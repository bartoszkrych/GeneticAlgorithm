#pragma once
#include "CKnapsackProblem.h"
#include <vector>
#include "CGeneticAlgorithm.h"

class CIndividual
{
public:
	CIndividual(CKnapsackProblem* cKnapsack,CGeneticAlgorithm* cGA);
	CIndividual(CKnapsackProblem* cKnapsack, CGeneticAlgorithm* cGA , int * piTable);
	~CIndividual();

	void vMutation(double dMutationProb);
	std::vector<CIndividual*> vCrossing(CIndividual* cSecondParent);

	CIndividual& operator+(CIndividual & pcOther);
	void operator++();

	double dGetFitness();
	int iGetGen(int iIndex);
	double dGetValueGen();

	void vDisplay();
private:
	void vSetFitness();
	int iGenerateInteger(int iFrom, int iTo);
	double dGenerateDouble(double dFrom, double dTo);

	int * pi_genotype;
	int i_count_gen;
	double d_fitness;
	double d_value_gen;
	double d_size_gen;

	CGeneticAlgorithm* c_ga;
	CKnapsackProblem* c_knapsack;
};

