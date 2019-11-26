//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_INDIVIDUAL_H
#define LAB4_INDIVIDUAL_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

class Individual {
private:
    std::string GENES;
    std::string TARGET;
    std::string chromosome;
    int fitness;

public:
    Individual(std::string chromosome);
    Individual mate(Individual parent2);
    int cal_fitness();
    float randNum(float start, float end);
    char mutatedGenes();
    std::string newGenome();

    int getFitness(){return fitness;}
    std::string getChromosone(){return chromosome;}
};


#endif //LAB4_INDIVIDUAL_H
