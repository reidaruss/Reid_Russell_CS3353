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
        std::cout << "Runtime of Brute Force: " << bTSP->getRunTime() << std::endl;
        delete bTSP;
    }
    // Dynamic Programming TSP
    else if(algo == 1)
    {
        dynamicProgTSP * dynProgTSP = new dynamicProgTSP(&nodes);
        dynProgTSP->run();
        std::cout << "Runtime of Dynamic Programming: " << dynProgTSP->getRunTime() << std::endl;
        delete dynProgTSP;
    }

}

void TSP::printSolution()
{

}