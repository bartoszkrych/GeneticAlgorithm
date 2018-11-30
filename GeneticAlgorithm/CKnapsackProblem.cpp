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

	pi_items_table = new double*[i_items_count];
	for (int i = 0; i < i_items_count; i++)
	{
		pi_items_table[i] = new double[2];
		pi_items_table[i][0] = dGenerateDouble(0.01, DEFAULT_VALUES);
		pi_items_table[i][1] = dGenerateDouble(0.01, DEFAULT_VALUES);
	}
}

CKnapsackProblem::CKnapsackProblem(double dKnapsackSize, int iItemsCount, double dMaxValueItm, double dMaxSizeItm)
{
	d_knapsack_size = dKnapsackSize;
	i_items_count = iItemsCount;

	pi_items_table = new double*[i_items_count];
	for (int i = 0; i < i_items_count; i++)
	{
		pi_items_table[i] = new double[2];
		pi_items_table[i][0] = dGenerateDouble(0.01, dMaxValueItm);
		pi_items_table[i][1] = dGenerateDouble(0.01, dMaxSizeItm);
	}
}

CKnapsackProblem::CKnapsackProblem(double dKnapsackSize, int iItemsCount)
{
	d_knapsack_size = dKnapsackSize;
	i_items_count = iItemsCount;

	pi_items_table = new double*[i_items_count];
	for (int i = 0; i < i_items_count; i++)
	{
		pi_items_table[i] = new double[2];
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


bool CKnapsackProblem::bSetNewValueOfItm(int iIndex, double iValue)
{
	if (iIndex >= d_knapsack_size || iIndex < 0) return false;

	pi_items_table[iIndex][0] = round(iValue * 100) / 100;
	return true;
}

bool CKnapsackProblem::bSetNewSizeOfItm(int iIndex, double iSize)
{
	if (iIndex >= d_knapsack_size || iIndex < 0) return false;

	pi_items_table[iIndex][1] = round(iSize * 100) / 100;
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

double CKnapsackProblem::dGetKnapsackSize()
{
	return d_knapsack_size;
}

void CKnapsackProblem::display()
{
	cout << "Capacity:	" << d_knapsack_size << endl <<"Count of items:	"<< i_items_count<<endl<<endl << "i|v	|s"<<endl;
		for (int j = 0; j < i_items_count; j++)
		{
			cout <<j<<"|"<<pi_items_table[j][0] << "	|"<< pi_items_table[j][1]<<endl;
		}
		cout << endl;
}


double CKnapsackProblem::dGenerateDouble(double dFrom, double dTo)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(dFrom, dTo);
	
	return round(dis(gen) * 100) / 100;
}

int CKnapsackProblem::iGenerateInteger(int iFrom, int iTo)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(iFrom, iTo);

	return dis(gen);
}


