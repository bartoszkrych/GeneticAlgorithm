#include "CIndividual.h"
#include <random>
#include "CGeneticAlgorithm.h"
using namespace std;

CIndividual::CIndividual(CKnapsackProblem* cKnapsack)
{
	c_knapsack = cKnapsack;
	i_size_genotype = c_knapsack->iGetItemsCount();
	d_fitness = 0;

	pi_genotype = new int [i_size_genotype];
	for (int i = 0; i < i_size_genotype; i++)
	{
		pi_genotype[i] =  iGenerateInteger(0,1);
	}

	vSetFitness();
}

CIndividual::~CIndividual()
{
	delete[] pi_genotype;
}

void CIndividual::vMutation()
{
	double d_mutation_prob = CGeneticAlgorithm::dGetMutationProb();

	for(int i = 0; i < i_size_genotype; i++)
	{
		double d_number = dGenerateDouble(0.0, 1.0);
		if(!(d_number>d_mutation_prob))
		{
			pi_genotype[i] += 1 % 2;
		}
	}
}

double CIndividual::dGetFitness()
{
	return d_fitness;
}

void CIndividual::vSetFitness()
{
	double d_fit_tmp = c_knapsack->dGetValueFromGen(&pi_genotype);

	if (d_fit_tmp <= c_knapsack->dGetKnapsackSize()) d_fitness = d_fit_tmp;
}

int CIndividual::iGenerateInteger(int iFrom, int iTo)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(iFrom, iTo);

	return dis(gen);
}

double CIndividual::dGenerateDouble(double dFrom, double dTo)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(dFrom, dTo);

	return dis(gen);
}
