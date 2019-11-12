//
// Created by Reid Russell on 11/5/19.
//

#include "TSP.h"

TSP::TSP()
{
    algo = -1;
}

void TSP::load(std::string fileName)
{
    file.setFileName(fileName);
    file.readFile();
}

void TSP::select(int n)
{
    algo = n;
}

void TSP::execute()
{
    std::vector<Node> nodes = file.getNodes();
    // Invalid Algorithm Selected
    if(algo == -1)
    {
        std::cout << "Algorithm not selected or invalid selection." << std::endl;
    }
    // Brute Force TSP
    else if(algo == 0)
    {
        bruteTSP * bTSP = new bruteTSP(file.getNodePs());
        bTSP->run();

        bruteRuntime = bTSP->getRunTime();
        bruteShortestPath = bTSP->getShortestPath();
        bruteTotalDist = bTSP->getTotalCost();

        delete bTSP;
    }
    // Dynamic Programming TSP
    else if(algo == 1)
    {
        dynamicProgTSP * dynProgTSP = new dynamicProgTSP(&nodes);
        dynProgTSP->run();

        dpRuntime = dynProgTSP->getRunTime();
        dpShortestPath = dynProgTSP->getShortestPath();
        dpTotalDist = dynProgTSP->getTotalCost();

        delete dynProgTSP;
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
        std::cout << "Brute Force TSP:::::::::::::::" << std::endl;
        std::cout << "Runtime of Brute Force: " << bruteRuntime << std::endl;
        std::cout << "Shortest Path: ";
        for(int i = 0; i < bruteShortestPath.size(); i++)
        {
            std::cout << bruteShortestPath[i].getId();
            if(i != bruteShortestPath.size() - 1)
                std::cout << " -> ";
        }
        std::cout << std::endl;
        std::cout << "Total Distance: " << bruteTotalDist << std::endl;
        std::cout <<"___________________________________" << std::endl;

    }
    // Dynamic Programming TSP
    else if(algo == 1)
    {
        std::cout << "DP TSP:::::::::::::::" << std::endl;
        std::cout << "Runtime of DP: " << dpRuntime << std::endl;
        std::cout << "Shortest Path: ";
        for(int i = 0; i < dpShortestPath.size(); i++)
        {
            std::cout << dpShortestPath[i].getId();
            if(i != dpShortestPath.size() - 1)
                std::cout << " -> ";
        }
        std::cout << std::endl;
        std::cout << "Total Distance: " << dpTotalDist << std::endl;
        std::cout <<"___________________________________" << std::endl;

    }

}