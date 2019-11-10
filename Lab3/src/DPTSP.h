//
// Created by Reid Russell on 11/5/19.
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

    std::vector<Node> nodes;
    std::vector<std::vector<float>> dist;

    std::vector<float> subtrees;
    std::vector<std::vector<bool> > state;

    std::vector<Node> path;

public:
    dynamicProgTSP(std::vector<Node>* nList);
    void calcDist();
    int findMin(int index);
    bool isVisited(int id);
    float tsp(int node, std::vector<bool> visited);
    void run();

};


#endif //LAB3_DPTSP_H
