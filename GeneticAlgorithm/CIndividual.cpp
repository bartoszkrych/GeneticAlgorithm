#include "CIndividual.h"
#include <random>
#include "CGeneticAlgorithm.h"
#include <iostream>
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

	d_size = c_knapsack->dGetSizeFromGen(pi_genotype);
	d_value_gen = c_knapsack->dGetValueFromGen(pi_genotype);
}

CIndividual::CIndividual(CKnapsackProblem* cKnapsack, int* piTable)
{
	c_knapsack = cKnapsack;
	i_size_genotype = c_knapsack->iGetItemsCount();
	d_fitness = 0;

	pi_genotype = new int[i_size_genotype];
	for (int i = 0; i < i_size_genotype; i++)
	{
		pi_genotype[i] = piTable[i];
	}
	vSetFitness();

	d_size = c_knapsack->dGetSizeFromGen(pi_genotype);
	d_value_gen = c_knapsack->dGetValueFromGen(pi_genotype);
}

CIndividual::~CIndividual()
{
	delete[] pi_genotype;
}

void CIndividual::vMutation(double dMutationProb)
{

	for(int i = 0; i < i_size_genotype; i++)
	{
		double d_number = dGenerateDouble(0.0, 1.0);
		if(!(d_number>dMutationProb))
		{
			pi_genotype[i] = (pi_genotype[i] + 1) % 2;
		}
	}
	d_fitness = 0;
	vSetFitness();
	d_size = c_knapsack->dGetSizeFromGen(pi_genotype);
	d_value_gen = c_knapsack->dGetValueFromGen(pi_genotype);

}

std::vector<CIndividual*> CIndividual::vCrossing(CIndividual* cSecondParent)
{
	vector<CIndividual*> v_children(0);
	int i_index_part = iGenerateInteger(1, i_size_genotype - 1);
	int ** pi_table = new int*[2];
	pi_table[0] = new int[i_size_genotype];
	pi_table[1] = new int[i_size_genotype];
	for(int j = 0; j<i_size_genotype; j++)
	{
		if (j < i_index_part) 
		{
			pi_table[0][j] = iGetGen(j);
			pi_table[1][j] = cSecondParent->iGetGen(j);
		}else
		{
			pi_table[0][j] = cSecondParent->iGetGen(j);
			pi_table[1][j] = iGetGen(j);
		}
	}
	v_children.push_back(new CIndividual(c_knapsack, pi_table[0]));
	v_children.push_back(new CIndividual(c_knapsack, pi_table[1]));
	return v_children;
}

double CIndividual::dGetFitness()
{
	return d_fitness;
}

int CIndividual::iGetGen(int iIndex)
{
	return pi_genotype[iIndex];
}

double CIndividual::dGetValueGen()
{
	return d_value_gen;
}

void CIndividual::display()
{
	cout << "Fitness:	" << d_fitness <<"	Size:		" << d_size<< "	[";
	for (int j = 0; j < i_size_genotype - 1; j++)
	{
		cout << pi_genotype[j] << ",";
	}
	cout << pi_genotype[i_size_genotype - 1] << "]" << endl;
}

void CIndividual::vSetFitness()
{
	double d_size = c_knapsack->dGetSizeFromGen(pi_genotype);

	if (d_size <= c_knapsack->dGetKnapsackSize()) d_fitness = c_knapsack->dGetValueFromGen(pi_genotype);
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


