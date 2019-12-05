//
// Created by Reid Russell on 12/4/19.
//

#include "Tabu.h"

/*
- maxIter is the stopping condition. Once tabu has make maxIter # of moves it will stop and print best found path
- initialNeighbor is that starting path, that will always start from the first node and end at the first node in the graph.

 */
Tabu::Tabu(std::vector<Node>* n)
{
    nodes = *n;
    neighborhoodSize = nodes.size();
    maxIter = 600;
    tListSize = 150;
    std::vector<Node> initialNeighbor = nodes;
    initialNeighbor.push_back(nodes[0]);
    curr.setPath(initialNeighbor);
    tabuList.push_front(curr);
    bestSoln = curr;
}


void Tabu::execute()
{
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point tempTime;
    std::chrono::duration<double> limit;
    int counter = 0;
    while(limit.count() < maxIter) // maxIter will determine when tabu stops searching
    {
        std::vector<Neighbor> neighborhood = genNeighbors();
        getNextMove(neighborhood);
        if(curr.getDist() < bestSoln.getDist()) // check if it has found new best solution
            bestSoln = curr;
        counter++;
        tempTime = std::chrono::high_resolution_clock::now();
        limit = std::chrono::duration_cast<std::chrono::duration<double>>(tempTime-t1);
        bestAtGen.push_back(curr.getDist());
    }


    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
    std::cout << "Runtime of Tabu: " << runtime.count() << std::endl;
    bestSoln.printPath(); // print best path found

}

std::vector<Neighbor> Tabu::genNeighbors()
{
    std::vector<Node> currPath = curr.getPath(); //used for swapping
    std::vector<Neighbor> neighborhood;
    std::vector<Node> temp = currPath; // actually swapping here
    for(int i = 1; i< curr.getSize()-1; i++)
    {

        for(int j = curr.getSize()-2; j > i; j--) {
            if(j <= i)
                break;
            Node t = temp[j];
            temp[j] = temp[i];
            temp[i] = t;
            Neighbor tN(temp);
            neighborhood.push_back(tN);
        }
    }

    return neighborhood;
}

void Tabu::getNextMove(std::vector<Neighbor> neighborhood)  // Insertion sort then choose from front
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
            {
                break;
            }
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
