//
// Created by Reid Russell on 11/5/19.
//

#include "bruteTSP.h"

// Set nodes to the vector of node pointers
bruteTSP::bruteTSP(std::vector<Node*> nList)
{
    nodes = nList;
}

// Calculate the distance for a particular permutation
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

// When smaller distance is found, save the current node order into a vector of nodes
void bruteTSP::buildShortestPath()
{
    if(shortestPath.size() != 0)
        shortestPath.clear();

    for(int i = 0; i < nodes.size(); i++)
        shortestPath.push_back(*nodes[i]);
}

// Use next_permutation to get every combination of the vector of node pointers
void bruteTSP::run()
{
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    float lowestFound = -1;
    nodes.push_back(nodes[0]); // Push starting node onto back to get path back to starting node
    while(std::next_permutation(nodes.begin() + 1, nodes.end() - 1))
    {
        float dist = 0;
        dist = calcDist();
        if(lowestFound == -1) {
            lowestFound = dist;
            buildShortestPath();
        }
        else if(dist < lowestFound) {
            lowestFound = dist;
            buildShortestPath();
        }
    }
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);

    std::cout << "Shortest distance found = " << lowestFound << std::endl;
    for(int i = 0; i < shortestPath.size(); i++)
        std::cout << shortestPath[i].getId() << "->";
    std::cout << std::endl;
}




