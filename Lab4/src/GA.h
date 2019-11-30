//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_GA_H
#define LAB4_GA_H
#include <string>
#include <iostream>
#include <vector>

#include "Individual.h"

class Genetic_Algo {
private:
    int popSize;
    std::vector<Individual> population;
public:
    Genetic_Algo();

    float randNum(float start, float end);
    std::string newGnome();
    void sortPop();
    void execute();


};


#endif //LAB4_GA_H
