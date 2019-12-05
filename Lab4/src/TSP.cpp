//
// Created by Reid Russell on 11/23/2019.
//
#include "TSP.h"

TSP::TSP()
{
    algo = -1;
}

void TSP::load(std::string fileName)
{
    f.setFileName(fileName);
    f.readFile();
}

void TSP::select(int n)
{
    algo = n;
}

void TSP::execute()
{

    std::vector<Node> nodes = f.getNodes();
    // Invalid Algorithm Selected
    if(algo == -1)
    {
        std::cout << "Algorithm not selected or invalid selection." << std::endl;
    }
        // GA
    else if(algo == 0)
    {
        Genetic_Algo g(&nodes, nodes.size());
        g.execute();
    }
        // Tabu
    else if(algo == 1)
    {
        Tabu t(&nodes);
        t.execute();
    }

}

void TSP::printSolution()
{
    // Invalid Algorithm Selected
    if(algo == -1)
    {
        std::cout << "Algorithm not selected or invalid selection." << std::endl;
    }
        // Brute Force TSP
    else if(algo == 0)
    {


    }
        // Dynamic Programming TSP
    else if(algo == 1)
    {


    }

}