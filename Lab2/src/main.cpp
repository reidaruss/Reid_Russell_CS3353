#include <iostream>
#include "Search.h"
#include "algorithm.h"
#include "LinkedList.h"
#include "AdjacencyList.h"





int main() {
    int start = 1;
    int end = 16;

//    Search s;
//    s.select(0);
//    s.execute(1,16);
//    s.select(1);
//    s.execute(1,16);

    Algorithm * d = new Search();
    for(int i = Algorithm::BFSSEARCH; i != Algorithm::LAST;i++)
    {
        d->select(i);
        d->execute(start, end);
        d->stats();
    }
    //d->display();
    //d->save();

    return 0;
}