#pragma once
#include "CKnapsackProblem.h"
#include <vector>

class CIndividual
{
public:
	CIndividual(CKnapsackProblem* cKnapsack);
	CIndividual(CKnapsackProblem* cKnapsack, int ** piTable);
	~CIndividual();

	void vMutation();
	std::vector<CIndividual*> vCrossing(CIndividual* cSecondParent);

	double dGetFitness();
	int iGetGen(int iIndex);
	double dGetValueGen();

	void display();

private:
	void vSetFitness();
	int iGenerateInteger(int iFrom, int iTo);
	double dGenerateDouble(double dFrom, double dTo);

	int * pi_genotype;
	int i_size_genotype;
	double d_fitness;
	double d_value_gen;

	CKnapsackProblem* c_knapsack;
};

