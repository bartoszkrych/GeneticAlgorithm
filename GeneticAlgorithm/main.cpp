#include <iostream>
#include <random>
#include "CIndividual.h"
#include "CGeneticAlgorithm.h"
using namespace std;

#include "CKnapsackProblem.h"


int main()
{
	int popSize = 4;//size of population
	double crossProb = 0.6;// cross prob
	double mutProb = 0.2; //mutation prob
	CKnapsackProblem* knap = new CKnapsackProblem(5.17,10,5,2);
	CGeneticAlgorithm* c_GA = new CGeneticAlgorithm(popSize, mutProb, crossProb, knap);

	//c_GA->vGenerateNewPopulation();
	knap->display();
	c_GA->vStartAlgorithm(5);

	system("pause");


	return 0;
}