//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_GA_H
#define LAB4_GA_H

#include <string>
#include <iostream>
#include <vector>
#include <chrono>

#include "Individual.h"
#include "Node.h"

class Genetic_Algo {
private:
    /// Functional ///
    std::vector<Node> nodes;
    int popSize;
    std::vector<Individual> population;
    float bestSoln;


    /// Stats ///
    std::vector<float> bestAtGen;
    std::chrono::duration<double> runtime;
public:
    Genetic_Algo(std::vector<Node>* n, int size);


    float randNum(float start, float end);
    void execute();

    /// Stats ///
    float getRunTime() {return runtime.count();}
    std::vector<float> getBestGen(){return bestAtGen;}
};


#endif //LAB4_GA_H
