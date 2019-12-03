//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_INDIVIDUAL_H
#define LAB4_INDIVIDUAL_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

#include "Node.h"

class Individual {
private:
    std::vector<Node> nodes;
    std::vector<Node> chromosome;
    float fitness;

public:
    //Individual();
    Individual(std::vector<Node> chromosome, std::vector<Node>* n);
    bool operator < (Individual const & ind);
//    bool operator = (Individual const & ind);
    Individual mate(Individual parent2);

    float calcDist();
    //int cal_fitness();

    float randNum(float start, float end);
    Node mutatedGenes();
    std::vector<Node> newGnome();
    void sortInds(std::vector<Individual>& pop);
    bool operator > (Individual const & ind);


    float getFitness(){return fitness;}
    std::vector<Node> getChromosome(){return chromosome;}
};


#endif //LAB4_INDIVIDUAL_H
