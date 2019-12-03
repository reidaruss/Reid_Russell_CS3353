//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_GA_H
#define LAB4_GA_H
#include <string>
#include <iostream>
#include <vector>

#include "Individual.h"
#include "Node.h"

class Genetic_Algo {
private:
    std::vector<Node> nodes;
    int popSize;
    std::vector<Individual> population;
public:
    Genetic_Algo(std::vector<Node>* n, int size);


    float randNum(float start, float end);
    std::string newGnome();
    void sortPop();
    void execute();


};


#endif //LAB4_GA_H
