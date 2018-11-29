#include <iostream>
#include <random>
using namespace std;

#include "CKnapsackProblem.h"

int generateNumber(int from,int to)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(from, to);

	return dis(gen);
}

void generatePopulation(int*** piTable, int countPop, int countBinCode)
{

	*piTable = new int*[countPop];
	for (int i = 0; i < countPop; i++)
	{
		(*piTable)[i] = new int[countBinCode];
		for (int j = 0; j < countBinCode; j++)
		{
			(*piTable)[i][j] = generateNumber(0,1);
		}
	}
}

void generateItems(int *** piTable, int maxValue, int maxSize, int countItems)
{

	*piTable = new int*[countItems];
	for (int i = 0; i < countItems; i++)
	{
		(*piTable)[i] = new int[2];
		(*piTable)[i][0] = generateNumber(1, maxValue);
		(*piTable)[i][1] = generateNumber(1, maxSize);

	}
	
}

void display(int*** tab, int countBinCode, int countPop)
{

	for (int i = 0; i < countPop; i++)
	{
		cout<< i + 1 << ": ";
		for (int j = 0; j < countBinCode; j++)
		{
			cout << (*tab)[i][j] << " ";
		}
		cout << endl;
	}
}

void displayValues(int *** populations, int countPop, int *** items, int countItems)
{
	int value = 0;
	int weight = 0;
	for (int i = 0; i < countPop; i++)
	{
		cout << i + 1 << ": ";
		for (int j = 0; j < countItems; j++)
		{
			cout << (*populations)[i][j];
			if ((*populations)[i][j] == 1)
			{
				value += (*items)[j][0];
				weight += (*items)[j][1];
			}
		}
		cout << ", value:" << value << ", weight:" << weight << endl;
		value = 0;
		weight = 0;
	}
}

void estimate(int *** populations, int countPop, int *** items, int countItems, int size)
{
	int weight = 0;
	int fitness = 0;
	int indi_1 = generateNumber(0, countPop - 1);
	int indi_2 = generateNumber(0, countPop - 1);
	for (int i = 0; i < countPop; i++)
	{
		cout << i + 1 << ": ";
		for (int j = 0; j < countItems; j++)
		{
			cout << (*populations)[i][j];
			if ((*populations)[i][j] == 1)
			{
				fitness += (*items)[j][0];
				weight += (*items)[j][1];
			}
		}
		if (weight > size)
		{
			fitness=0;
		}
		cout << ", value:" << weight << ", fitness:" << fitness;
		if(i == indi_1 || i == indi_2)
		{
			cout << " <-";
		}
		cout << endl;
		fitness = 0;
		weight = 0;
	}
		cout << endl;
	
}

int main()
{
	/*
	int popSize=4;//size of population
	int crossProb;// cross prob
	int mutProb;; //mutation prob
	int countItems=4;
	int backpackSize = 7;
	int ** populationsT;
	int **itemsT;
	generatePopulation(&populationsT, popSize, countItems);
	generateItems(&itemsT, 5, 4, countItems);

	display(&populationsT, 4, countItems);
	cout << endl << "i |v|w|"<<endl;
	display(&itemsT, 2, countItems);
	cout << endl;
	//displayValues(&populationsT, popSize, &itemsT, countItems);
	estimate(&populationsT, popSize, &itemsT, countItems,backpackSize);
	*/

	system("pause");


	return 0;
}