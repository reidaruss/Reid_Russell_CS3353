#include <iostream>
#include "fileIn.h"
#include "TSP.h"
#include "Algorithm.h"

int main() {


    fileIn f("../pos.txt");
    f.readFile();

    Algorithm * d = new TSP();
    for(int i = Algorithm::BRUTETSP; i != Algorithm::LAST;i++)
    {
        d->select(i);
        d->execute(start, end);
        d->printSolution();
    }

    delete d;


    return 0;
}