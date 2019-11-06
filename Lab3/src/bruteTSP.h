//
// Created by Reid Russell on 11/5/19.
//

#ifndef LAB3_BRUTETSP_H
#define LAB3_BRUTETSP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

#include "Node.h"


class bruteTSP {
private:
    std::vector<Node*> nodes;
    std::vector<Node> shortestPath;
    std::chrono::duration<double> runtime;

public:
    bruteTSP(std::vector<Node*> nList);

    void buildShortestPath();

    float calcDist();
    void run();
    float getRunTime() {return runtime.count();}


};


#endif //LAB3_BRUTETSP_H
