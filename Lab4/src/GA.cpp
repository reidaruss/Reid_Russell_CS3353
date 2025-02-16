//
// Created by Reid Russell on 11/23/2019.
//

// Referenced from https://www.geeksforgeeks.org/genetic-algorithms/

#include "GA.h"

Genetic_Algo::Genetic_Algo(std::vector<Node>* n, int size)
{
    nodes = *n;
    popSize = nodes.size()*15;
    bestSoln = 0;
    //popSize = 1000;
//    popSize = 50;

}

float Genetic_Algo::randNum(float start, float end)
{
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}


void Genetic_Algo::execute()
{
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    // current generation
    int generation = 0;

    bool found = false;
    int difCounter = 0;
    float prevDif = 0;
    Individual ind(nodes, &nodes);
    // create initial population
    for(int i = 0;i<popSize;i++)
    {
        Individual temp(ind.newGnome(), &nodes);
        population.push_back(temp);
    }
    bestSoln = population[0].getFitness();
    bestAtGen.push_back(bestSoln);
    int counter = 0;
    std::chrono::high_resolution_clock::time_point tempTime;
    std::chrono::duration<double> limit;
    while(limit.count() < 10)
    {
        population[0].sortInds(population); // Sort the population, first element will be shortest distance
        bestSoln = population[0].getFitness();
        bestAtGen.push_back(bestSoln);


        ////// COMMENT OUT WHEN RUNNING UNTIL MAX TIME

        // if the individual having lowest fitness score ie.
        // 0 then we know that we have reached to the target
        // and break the loop
//        float dif = population[popSize/10].getFitness() - population[0].getFitness();
//        if(dif == 0)
//        {
//            counter ++;
//            if(counter > nodes.size()*5)
//            {
//                found = true;
//                break;
//            }
//
//        }
//        else
//            counter = 0;
//
//        if(prevDif == dif)
//        {
//            if(difCounter >= nodes.size()*(nodes.size()/4))
//            {
//                found = true;
//                break;
//            }
//            else
//                difCounter ++;
//        }
//        else
//        {
//            prevDif = dif;
//            difCounter = 0;
//        }



        // Otherwise generate new offsprings for new generation
        std::vector<Individual> new_generation;

        // Perform Elitism, 10% of fittest population
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

        //////// STATS ///////

//        std::cout<< "Generation: " << generation << "\t";
////        std::cout<< "Path: ";
////        for(int i = 0; i < population[0].getChromosome().size(); i++)
////        {
////            std::cout << population[0].getChromosome()[i].getId() <<"\t";
////        }
//        std::cout<< "Fitness: "<< population[0].getFitness() <<"\t";
//        std::cout << "Difference: " << population[9].getFitness() - population[0].getFitness() << "\t";
//        std::cout << "Counter: " << counter << "\t";
//        std::cout << "DifCounter: " << difCounter << "\n";
        generation++;
        tempTime = std::chrono::high_resolution_clock::now();
        limit = std::chrono::duration_cast<std::chrono::duration<double>>(tempTime-t1);
//        std::cout << limit.count() << std::endl;
    }
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
    std::cout << "Runtime: " << runtime.count() << "\t";
    std::cout<< "Generation: " << generation << "\t";
    std::cout<< "Path: ";
    for(int i = 0; i < population[0].getChromosome().size(); i++)
    {
        std::cout << population[0].getChromosome()[i].getId() <<"\t";
    }
    std::cout<< "Fitness: "<< population[0].getFitness() <<"\t";
    std::cout << "Difference: " << population[9].getFitness() - population[0].getFitness() << "\t";
    std::cout << "DifCounter: " << difCounter << "\n";
    std::cout << std::endl;
}
