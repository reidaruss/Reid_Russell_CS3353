//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_TSP_H
#define LAB4_TSP_H

#include <iostream>

#include "Algorithm.h"
#include "file.h"
#include "Node.h"
#include "GA.h"
#include "Tabu.h"
//#include "Individual.h"

class TSP : public Algorithm{
private:
    int algo;
    file f;

    float bruteRuntime;
    float dpRuntime;

    std::vector<Node> bruteShortestPath;
    std::vector<Node> dpShortestPath;

    float bruteTotalDist;
    float dpTotalDist;

public:
    TSP();

    void load(std::string fileName);
    void select(int n);
    void execute();
    void printSolution();

};

#endif //LAB4_TSP_H
