//
// Created by Reid Russell on 11/5/19.
//

#include "bruteTSP.h"

bruteTSP::bruteTSP(std::vector<Node*> nList)
{
    nodes = nList;
}

float bruteTSP::calcDist()
{
    float distance = 0;
    for(int i = 0; i < nodes.size() -1; i++)
    {
        std::vector<float> posA = nodes[i]->getPos();
        std::vector<float> posB = nodes[i+1]->getPos();
        float tempDist = 0;
        tempDist =  std::sqrt(std::pow(posB[0]-posA[0],2) + std::pow(posB[1]-posA[1],2)
                + std::pow(posB[2]-posA[2],2));
        distance += tempDist;
    }

    return distance;
}

void bruteTSP::buildShortestPath()
{
    
}

void bruteTSP::run()
{
    float lowestFound = -1;
    while(std::next_permutation(nodes.begin() + 1, nodes.end()))
    {
        float dist = 0;
        dist = calcDist();
        if(lowestFound == -1) {
            lowestFound = dist;
            buildShortestPath();
        }
        else if(dist < lowestFound) {
            lowestFound = dist;
        }
    }

    cout << "Shortest distance found = " << lowestFound << std::endl;
}
