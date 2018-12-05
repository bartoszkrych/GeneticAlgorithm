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
	int i_population_size = 5;//size of population
	double d_cross_prob = 0.6;// cross prob
	double d_mutation_prob = 0.2; //mutation prob
	double d_capacity_knap = 4.17;
	int i_item_count = 5;
	double d_item_max_value = 5.99;
	double d_item_max_size = 3.01;

	if(
		d_item_max_size>=0.01 
		&& d_item_max_value>=0
		&& i_item_count>0
		&& d_capacity_knap
		&& d_mutation_prob >= 0
		&& d_mutation_prob <= 1
		&& d_cross_prob >= 0
		&& d_cross_prob <= 1
		&& i_population_size > 1
	)
	{
		CKnapsackProblem* knap = new CKnapsackProblem(d_capacity_knap, i_item_count, d_item_max_value, d_item_max_size);
		CGeneticAlgorithm* c_GA = new CGeneticAlgorithm(i_population_size, d_mutation_prob, d_cross_prob, knap);


		knap->vDisplay();
		//c_GA->vGenerateNewPopulation();
		c_GA->vStartAlgorithm(3);

		delete knap;
		delete c_GA;
	}else
	{
		cout << "Something wrong! Check your data." << endl;
	}


	_CrtDumpMemoryLeaks();
	system("pause");


	return 0;
}
