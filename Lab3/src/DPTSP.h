//
// Created by Reid Russell on 11/5/19.
//
//


#ifndef LAB3_DPTSP_H
#define LAB3_DPTSP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

#include "Node.h"


class dynamicProgTSP {

private:
    float tCost;
    std::vector<Node> shortestPath;

    std::vector<Node> nodes;
    std::vector<std::vector<float>> dist;

    std::vector<std::vector<float>> subtrees;
    std::vector<Node> path;
    std::vector<float> minDists;

    std::chrono::duration<double> runtime;


public:
    dynamicProgTSP(std::vector<Node>* nList);

    void calcDist();
    float tsp(int visited, int pos);
    void constructPath();
    void run();

    float getRunTime() {return runtime.count();}
    std::vector<Node> getShortestPath() {return shortestPath;}
    float getTotalCost(){return tCost;}
};

#endif //LAB3_DPTSP_H
