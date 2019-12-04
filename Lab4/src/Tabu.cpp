//
// Created by Reid Russell on 12/4/19.
//

#include "Tabu.h"

Tabu::Tabu(std::vector<Node>* n)
{
    nodes = *n;
    neighborhoodSize = nodes.size();
    maxIter = 10000;
    tListSize = 50;
    std::vector<Node> initialNeighbor = nodes;
    initialNeighbor.push_back(nodes[0]);
    curr.setPath(initialNeighbor);
    tabuList.push_front(curr);
    bestSoln = curr;
}

void Tabu::execute()
{
    int counter = 0;
    while(counter < maxIter)
    {
        std::vector<Neighbor> neighborhood = genNeighbors();
        getNextMove(neighborhood);
        if(curr.getDist() < bestSoln.getDist())
            bestSoln = curr;
        counter++;
    }

    bestSoln.printPath();

}

std::vector<Neighbor> Tabu::genNeighbors()
{
    std::vector<Node> currPath = curr.getPath();
    std::vector<Neighbor> neighborhood;
    std::vector<Node> temp = currPath;
    for(int j = 1; j < curr.getSize()-3; j++) {
        Node t = temp[j];
        temp[j] = temp[j + 2];
        temp[j + 2] = t;
        Neighbor tN(temp);
        neighborhood.push_back(tN);
    }
    return neighborhood;
}

void Tabu::getNextMove(std::vector<Neighbor> neighborhood)
{
    int j;
    Neighbor key = neighborhood[0];
    for(int i = 0; i < neighborhood.size(); i ++)
    {
        key = neighborhood[i];
        j = i-1;

        while(j >= 0 && neighborhood[j].getDist() > key.getDist())
        {
            neighborhood[j+1] = neighborhood[j];
            j = j-1;
        }
        neighborhood[j + 1] = key;
    }
    std::deque<Neighbor>::iterator it;
    for(int i = 0; i < neighborhood.size(); i++)
    {
        for(it = tabuList.begin(); it != tabuList.end(); ++it)
        {
            Neighbor temp(*it);
            if(neighborhood[i] == temp)
                break;
            else if(it == tabuList.end()-1) {
                curr = neighborhood[i];
                tabuList.push_front(curr);
                if(tabuList.size() > tListSize)
                    tabuList.pop_back();
                return;
            }
        }
    }
}
