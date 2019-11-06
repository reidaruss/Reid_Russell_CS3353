//
// Created by Reid Russell on 11/5/19.
//

#ifndef LAB3_BRUTETSP_H
#define LAB3_BRUTETSP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Node.h"


class bruteTSP {
private:
    std::vector<Node*> nodes;
    std::vector<Node> shortestPath;

public:
    bruteTSP(std::vector<Node*> nList);

    void buildShortestPath();

    float calcDist();
    void run();


};


#endif //LAB3_BRUTETSP_H
