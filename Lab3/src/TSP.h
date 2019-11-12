//
// Created by Reid Russell on 11/5/19.
//

#ifndef LAB3_TSP_H
#define LAB3_TSP_H

#include <iostream>

#include "Algorithm.h"
#include "fileIn.h"
#include "bruteTSP.h"
#include "DPTSP.h"
#include "Node.h"


class TSP : public Algorithm{
private:
    int algo;
    fileIn file;

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


#endif //LAB3_TSP_H
