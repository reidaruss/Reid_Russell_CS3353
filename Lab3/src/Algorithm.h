//
// Created by Reid Russell on 11/5/19.
//

#ifndef LAB3_ALGORITHM_H
#define LAB3_ALGORITHM_H

#include <iostream>

class Algorithm
{
public:
    virtual void load(std::string fileName) = 0;
    virtual void select(int n) = 0;
    virtual void execute() = 0;
    virtual void printSolution() = 0;

    enum algos{BRUTETSP=0,DPTSP,LAST};
};

#endif //LAB3_ALGORITHM_H
