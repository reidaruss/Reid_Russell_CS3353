//
// Created by Reid Russell on 12/4/19.
//

#ifndef LAB4_TABU_H
#define LAB4_TABU_H

#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <queue>

#include "Node.h"
#include "Neighbor.h"

class Tabu {
private:
    std::vector<Node> nodes;
    int neighborhoodSize;
    int maxIter; //number of max iterations (stopping condition)
    Neighbor bestSoln; //best solution so far found
    Neighbor curr; //current position
    std::deque<Neighbor> tabuList;
    int tListSize;


public:
    Tabu(std::vector<Node>* n);
    void execute();

    std::vector<Neighbor> genNeighbors();
    void getNextMove(std::vector<Neighbor> neighborhood);

};


#endif //LAB4_TABU_H
