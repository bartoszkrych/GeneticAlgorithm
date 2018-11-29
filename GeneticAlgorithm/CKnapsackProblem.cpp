#include "CKnapsackProblem.h"
#include <random>
#include <iostream>

using namespace std;

#define DEFAULT_SIZE 4
#define DEFAULT_VALUES 5
#define DEFAULT_KNAPSACK 7

CKnapsackProblem::CKnapsackProblem()
{
	d_knapsack_size = DEFAULT_KNAPSACK;
	i_items_count = DEFAULT_SIZE;

	pi_items_table = new int*[i_items_count];
	for (int i = 0; i < i_items_count; i++)
	{
		pi_items_table[i] = new int[2];
		pi_items_table[i][0] = dGenerateDouble(0.01, DEFAULT_VALUES);
		pi_items_table[i][1] = dGenerateDouble(0.01, DEFAULT_VALUES);
	}
}

CKnapsackProblem::CKnapsackProblem(double dKnapsackSize, int iItemsCount, double dMaxValueItm, double dMaxSizeItm)
{
	d_knapsack_size = dKnapsackSize;
	i_items_count = iItemsCount;

	pi_items_table = new int*[i_items_count];
	for (int i = 0; i < i_items_count; i++)
	{
		pi_items_table[i] = new int[2];
		pi_items_table[i][0] = dGenerateDouble(0.01, dMaxValueItm);
		pi_items_table[i][1] = dGenerateDouble(0.01, dMaxSizeItm);
	}
}

CKnapsackProblem::CKnapsackProblem(double dKnapsackSize, int iItemsCount)
{
	d_knapsack_size = dKnapsackSize;
	i_items_count = iItemsCount;

	pi_items_table = new int*[i_items_count];
	for (int i = 0; i < i_items_count; i++)
	{
		pi_items_table[i] = new int[2];
		pi_items_table[i][0] = dGenerateDouble(0.01, DEFAULT_VALUES);
		pi_items_table[i][1] = dGenerateDouble(0.01, DEFAULT_VALUES);
	}
}

CKnapsackProblem::~CKnapsackProblem()
{
	for(int i = 0; i < i_items_count; i++)
	{
		delete[] pi_items_table[i];
	}

	delete[] pi_items_table;
}



bool CKnapsackProblem::bSetNewValueOfItm(int iIndex, int iValue)
{
	if (iIndex >= d_knapsack_size || iIndex < 0) return false;

	pi_items_table[iIndex][0] = iValue;
	return true;
}

bool CKnapsackProblem::bSetNewSizeOfItm(int iIndex, int iSize)
{
	if (iIndex >= d_knapsack_size || iIndex < 0) return false;

	pi_items_table[iIndex][1] = iSize;
	return true;
}

double CKnapsackProblem::dGetValueFromGen(int** piTable)
{
	double d_value_gen=0.0;
	for(int i = 0; i < i_items_count; i++)
	{
		if ((*piTable)[i] == 1) d_value_gen += pi_items_table[i][0];
	}
	return d_value_gen;
}

double CKnapsackProblem::dGetSizeFromGen(int** piTable)
{
	double d_size_gen = 0.0;
	for (int i = 0; i < i_items_count; i++)
	{
		if ((*piTable)[i] == 1) d_size_gen += pi_items_table[i][1];
	}
	return d_size_gen;
}

int CKnapsackProblem::iGetItemsCount()
{
	return i_items_count;
}

double CKnapsackProblem::iGetKnapsackSize()
{
	return d_knapsack_size;
}



double CKnapsackProblem::dGenerateDouble(double dFrom, double dTo)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(dFrom, dTo);
	
	return dis(gen);
}

int CKnapsackProblem::iGenerateInteger(int iFrom, int iTo)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(iFrom, iTo);

	return dis(gen);
}


