#include "CGeneticAlgorithm.h"
#include <random>
#include <iostream>


CGeneticAlgorithm::CGeneticAlgorithm(int iPopulationSize, double dMutationProb, double dCrossProb,CKnapsackProblem *cKnapsackProblem)
{
	i_population_size = iPopulationSize;
	d_mutation_prob = dMutationProb;
	d_cross_prob = dCrossProb;
	c_knapsack_problem = cKnapsackProblem;
	c_tab_population = new CIndividual*[i_population_size];
	for (int i = 0; i < i_population_size; i++)
	{
		c_tab_population[i] = new CIndividual(c_knapsack_problem);
	}
	c_best_individual = c_tab_population[0];
	for(int i = 1 ; i < i_population_size;i++)
	{
		if(c_tab_population[i]->dGetFitness()>c_best_individual->dGetFitness())
		{
			c_best_individual = c_tab_population[i];
		}
	}
}
CGeneticAlgorithm::~CGeneticAlgorithm()
{
	delete[] c_tab_population;
	delete c_best_individual;
}

void CGeneticAlgorithm::vStartAlgorithm(int iIter)
{
	int i_iter_population = 0;
	while(i_iter_population!=iIter)
	{
		vGenerateNewPopulation();
		i_iter_population++;
	}

	std::cout << "###	POP	###" << std::endl;
	for (int i = 0; i < i_population_size; i++)
	{
		c_tab_population[i]->display();
	}
	std::cout << "THE BEST IS: "<< std::endl; c_best_individual->display();

}//CGeneticAlgorithm::vGeneratePopulation(int iIter)
void CGeneticAlgorithm::vGenerateNewPopulation()
{
	std::cout << "###	POP	###"<< std::endl;
	for (int i = 0; i < i_population_size; i++)
	{
		c_tab_population[i]->display();
	}
	int i_random_number1;
	int i_random_number2;
	int i_children_count = 0;
	int i_index_best = -1;

	CIndividual ** pc_new_population = new CIndividual*[i_population_size];

	bool b_is_offspring = false;

	while (i_children_count < i_population_size)
	{
		int *pi_parents = new int[2];

		for (int i = 0; i < 2; i++)
		{
			i_random_number1 = iGenerateInteger(0, i_population_size - 1);
			i_random_number2 = i_random_number1;

			while (i_random_number2 == i_random_number1)
			{
				i_random_number2 = iGenerateInteger(0, i_population_size - 1);
			}

			if (c_tab_population[i_random_number1]->dGetFitness() >= c_tab_population[i_random_number2]->dGetFitness())
			{
				pi_parents[i] = i_random_number1;
			}
			else//if(c_tab_population[i_random_number1]->dGetFitness() >= c_tab_population[i_random_number2]->dGetFitness())
			{
				pi_parents[i] = i_random_number2;
			} // ELSE c_tab_population[i_random_number1]->dGetFitness() >= c_tab_population[i_random_number2]->dGetFitness())
		}//	for(int i = 0; i < 2; i++)

		double d_crossing = dGenerateDouble(0, 1);

		if (d_crossing <= d_cross_prob)
		{
			//b_is_offspring = true;
			std::vector <CIndividual*> children = c_tab_population[pi_parents[0]]->vCrossing(c_tab_population[pi_parents[1]]);
			children[0]->vMutation(d_mutation_prob);
			pc_new_population[i_children_count++] = children[0];
			if(i_children_count==i_population_size)
			{
				delete children[1];
			}else
			{
				children[1]->vMutation(d_mutation_prob);
				pc_new_population[i_children_count++] = children[1];
			}//if(i_children_count==i_population_size)
		}//if (d_crossing <= d_cross_prob)
		delete[] pi_parents;
	}//while(i_children_count >= i_population_size)

	for (int i = 0; i < i_population_size; i++)
	{
		if (c_best_individual == c_tab_population[i]) c_tab_population[i]=NULL;
	}//for (int i = 0; i < i_population_size; i++)

	delete[] c_tab_population;
	//c_tab_population = NULL;
	c_tab_population = pc_new_population;
	i_index_best = -1;
	double d_fitness_best = -1;
	for (int i = 0; i < i_population_size;i++)
	{
		if (c_tab_population[i]->dGetFitness() > d_fitness_best) {
			i_index_best = i;
			d_fitness_best = c_tab_population[i]->dGetFitness();
		}
	}//for (int i = 1; i < i_population_size;i++)

	if (i_index_best != -1) bMatchBestIndividual(c_tab_population[i_index_best]);


	//std::cout << std::endl << c_best_individual->dGetFitness();
}

bool CGeneticAlgorithm::bMatchBestIndividual(CIndividual* cToMatch)
{
	if(cToMatch->dGetFitness()>c_best_individual->dGetFitness())
	{
		delete c_best_individual;
		c_best_individual = cToMatch;
		return true;
	}
	return false;
}

int CGeneticAlgorithm::iGenerateInteger(int iFrom, int iTo)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(iFrom, iTo);

	return dis(gen);
}

double CGeneticAlgorithm::dGenerateDouble(double dFrom, double dTo)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(dFrom, dTo);

	return dis(gen);
}

