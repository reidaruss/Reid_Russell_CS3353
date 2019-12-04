//
// Created by Reid Russell on 11/23/2019.
//

#include "Individual.h"



Individual::Individual(std::vector<Node> chromosome, std::vector<Node>* n)
{
    this->nodes = *n;
    this->chromosome = chromosome;
    fitness = calcDist();
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
    Individual key = pop[0];
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
    std::vector<Node> child_chromosome;
    std::vector<Node> parB = par2.getChromosome();
    child_chromosome.push_back(nodes[0]);
    int len = chromosome.size();
    while(child_chromosome.size() < nodes.size()) {
        for (int i = 0; i < len; i++) {
            // random probability
            float p = randNum(0, 100) / 100;

            // if prob is less than 0.45, insert gene
            // from parent 1

            if (p < 0.425) {
                for (int j = 0; j < child_chromosome.size(); j++) {
                    if (chromosome[i].getId() == child_chromosome[j].getId())
                        break;
                    else if (j == child_chromosome.size() - 1)
                        child_chromosome.push_back(chromosome[i]);
                }
            }
                // if prob is between 0.45 and 0.90, insert
                // gene from parent 2
            else if (p < 0.875) {
                for (int j = 0; j < child_chromosome.size(); j++) {
                    if (parB[i].getId() == child_chromosome[j].getId())
                        break;
                    else if (j == child_chromosome.size() - 1)
                        child_chromosome.push_back(parB[i]);
                }
            }

                // otherwise insert random gene(mutate),
                // for maintaining diversity
            else {
                Node n = mutatedGenes();
                for (int j = 0; j < child_chromosome.size(); j++) {
                    if (n.getId() == child_chromosome[j].getId())
                        break;
                    else if (j == child_chromosome.size() - 1)
                        child_chromosome.push_back(n);
                }
            }


        }
    }

    child_chromosome.push_back(nodes[0]);
    // create new Individual(offspring) using
    // generated chromosome for offspring
    return Individual(child_chromosome, &nodes);
}



// Calculate the distance for a particular permutation
float Individual::calcDist()
{
    float distance = 0;
    for(int i = 0; i < chromosome.size() -1; i++)
    {
        std::vector<float> posA = chromosome[i].getPos();
        std::vector<float> posB = chromosome[i+1].getPos();
        float tempDist = 0;
        tempDist =  std::sqrt(std::pow(posB[0]-posA[0],2) + std::pow(posB[1]-posA[1],2)
                              + std::pow(posB[2]-posA[2],2));
        distance += tempDist;
    }

    return distance;
}



// Function to generate random numbers in given range
float Individual::randNum(float start, float end)
{
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

// Create random genes for mutation
Node Individual::mutatedGenes()
{
    int len = nodes.size();
    int r = randNum(0, len-1);
    return nodes[r];
}

std::vector<Node> Individual::newGnome()
{
    int len = nodes.size();
    std::vector<Node> gnome;
    gnome.push_back(nodes[0]);
    while(gnome.size() < nodes.size()){
        Node n = mutatedGenes();
        for(int j = 0; j < gnome.size(); j++)
        {
            if(n.getId() == gnome[j].getId())
                break;
            else if(j == gnome.size()-1)
                gnome.push_back(n);
        }
    }
    gnome.push_back(nodes[0]);
    return gnome;
}