#include <iostream>
#include <random>
#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>  
#include <crtdbg.h>



int main()
{
	int popSize = 4;//size of population
	double crossProb = 0.6;// cross prob
	double mutProb = 0.2; //mutation prob

	CKnapsackProblem* knap = new CKnapsackProblem(4,5,5,2);
	CGeneticAlgorithm* c_GA = new CGeneticAlgorithm(popSize, mutProb, crossProb, knap);

	
	knap->display();
	//c_GA->vGenerateNewPopulation();
	c_GA->vStartAlgorithm(5);

	delete knap;
	delete c_GA;

	_CrtDumpMemoryLeaks();
	system("pause");


	return 0;
}