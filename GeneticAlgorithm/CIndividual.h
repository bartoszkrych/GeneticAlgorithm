#pragma once
#include "CKnapsackProblem.h"

class CIndividual
{
public:
	CIndividual(CKnapsackProblem* cKnapsack);
	~CIndividual();

	void vMutation();

	double dGetFitness();

private:
	void vSetFitness();
	int iGenerateInteger(int iFrom, int iTo);
	double dGenerateDouble(double dFrom, double dTo);

	int * pi_genotype;
	int i_size_genotype;
	double d_fitness;

	CKnapsackProblem* c_knapsack;
};

