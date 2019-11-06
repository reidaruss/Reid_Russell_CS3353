//
// Created by Reid Russell on 11/5/19.
//

#include "TSP.h"

TSP::TSP()
{
    algo = -1;
}

void TSP::select(int n)
{
    algo = n;
}

void TSP::execute()
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

void TSP::printSolution()
{

}