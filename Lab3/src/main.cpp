
#include "Algorithm.h"
#include "TSP.h"

int main() {

    Algorithm * d = new TSP();
    //d->load("../pos.txt");
    //d->load("../pos10.txt");
    d->load("../sampleGraphs/pos11.txt");
    for(int i = Algorithm::BRUTETSP; i != Algorithm::LAST;i++)
    {
        d->select(i);
        d->execute();
        d->printSolution();
    }

    delete d;


    return 0;
}