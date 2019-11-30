//
// Created by Reid Russell on 11/23/2019.
//

#include "Individual.h"


Individual::Individual()
{
    TARGET = "I love GeeksforGeeks";
    GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP ";
    this->chromosome = newGnome();
    fitness = cal_fitness();
}

Individual::Individual(std::string chromosome)
{
    TARGET = "I love GeeksforGeeks";
    GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP";
    this->chromosome = chromosome;
    fitness = cal_fitness();
}

bool Individual::operator <(Individual const& ind)
{
    return this->fitness < ind.fitness;
}

bool Individual::operator >(Individual const& ind)
{
    return this->fitness > ind.fitness;
}

void Individual::sortInds(std::vector<Individual>& pop)
{
    int j;
    Individual key;
    for(int i = 0; i < pop.size(); i ++)
    {
        key = pop[i];
        j = i-1;

        while(j >= 0 && pop[j] > key)
        {
            pop[j+1] = pop[j];
            j = j-1;
        }
        pop[j + 1] = key;
    }
}

//bool Individual::operator=(Individual const &ind)
//{
//    return this->fitness == ind.fitness;
//}

// Perform mating and produce new offspring
Individual Individual::mate(Individual par2)
{
    // chromosome for offspring
    std::string child_chromosome = "";

    int len = chromosome.size();
    for(int i = 0;i<len;i++)
    {
        // random probability
        float p = randNum(0, 100)/100;

        // if prob is less than 0.45, insert gene
        // from parent 1
        if(p < 0.45)
            child_chromosome += chromosome[i];

            // if prob is between 0.45 and 0.90, insert
            // gene from parent 2
        else if(p < 0.90)
            child_chromosome += par2.chromosome[i];

            // otherwise insert random gene(mutate),
            // for maintaining diversity
        else
            child_chromosome += mutatedGenes();
    }

    // create new Individual(offspring) using
    // generated chromosome for offspring
    return Individual(child_chromosome);
}


// Calculate fittness score, it is the number of
// characters in string which differ from target
// string.
int Individual::cal_fitness()
{
    int len = TARGET.size();
    int fitness = 0;
    for(int i = 0;i<len;i++)
    {
        if(chromosome[i] != TARGET[i])
            fitness++;
    }
    return fitness;
}

// Function to generate random numbers in given range
float Individual::randNum(float start, float end)
{
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

// Create random genes for mutation
char Individual::mutatedGenes()
{
    int len = GENES.size();
    int r = randNum(0, len-1);
    return GENES[r];
}

std::string Individual::newGnome()
{
    int len = TARGET.length();
    std::string gnome = "";
    for(int i = 0;i<len;i++)
        gnome += mutatedGenes();
    return gnome;
}