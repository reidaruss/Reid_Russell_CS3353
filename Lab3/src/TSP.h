//
// Created by Reid Russell on 11/5/19.
//

#ifndef LAB3_TSP_H
#define LAB3_TSP_H

#include <iostream>

#include "Algorithm.h"
#include "bruteTSP.h"
#include "DPTSP.h"

class TSP : public Algorithm{
private:
    int algo;

public:
    TSP();

    void select(int n);
    void execute();
    void printSolution();

};


#endif //LAB3_TSP_H
