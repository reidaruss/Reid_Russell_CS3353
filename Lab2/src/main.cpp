#include <iostream>
#include "Search.h"
#include "algorithm.h"
#include "LinkedList.h"
#include "AdjacencyList.h"





int main(int argc, char* argv[]) {
    int start = stoi(argv[1]);
    int end = stoi(argv[2]);



    Algorithm * d = new Search();
    for(int i = Algorithm::BFSSEARCH; i != Algorithm::LAST;i++)
    {

        d->select(i);
//        d->reportTests();
        d->execute(start, end);
        d->stats();
    }
    //d->display();

    delete d;


    return 0;
}