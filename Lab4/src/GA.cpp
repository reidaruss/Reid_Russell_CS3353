//
// Created by Reid Russell on 11/23/2019.
//

#include "GA.h"

GA::GA()
{
    popSize = 100;
}

void GA::execute()
{
    srand((unsigned)(time(0)));

    // current generation
    int generation = 0;

    std::vector<Individual> population;
    bool found = false;

    // create initial population
    for(int i = 0;i<popSize;i++)
    {
        std::string gnome = createGnome();
        population.push_back(Individual(gnome));
    }

    while(!found)
    {
        // sort the population in increasing order of fitness score
        sort(population.begin(), population.end());

        // if the individual having lowest fitness score ie.
        // 0 then we know that we have reached to the target
        // and break the loop
        if(population[0].getFitness() <= 0)
        {
            found = true;
            break;
        }

        // Otherwise generate new offsprings for new generation
        std::vector<Individual> new_generation;

        // Perform Elitism, that mean 10% of fittest population
        // goes to the next generation
        int s = (10*popSize)/100;
        for(int i = 0;i<s;i++)
            new_generation.push_back(population[i]);

        // From 50% of fittest population, Individuals
        // will mate to produce offspring
        s = (90*popSize)/100;
        for(int i = 0;i<s;i++)
        {
            int len = population.size();
            int r = randNum(0, 50);
            Individual parent1 = population[r];
            r = randNum(0, 50);
            Individual parent2 = population[r];
            Individual offspring = parent1.mate(parent2);
            new_generation.push_back(offspring);
        }
        population = new_generation;
        std::cout<< "Generation: " << generation << "\t";
        std::cout<< "String: "<< population[0].getChromosome() <<"\t";
        std::cout<< "Fitness: "<< population[0].getFitness() << "\n";

        generation++;
    }
    std::cout<< "Generation: " << generation << "\t";
    std::cout<< "String: "<< population[0].getChromosome() <<"\t";
    std::cout<< "Fitness: "<< population[0].getFitness() << "\n";
}
