#include <iostream>
#include "Search.h"
#include "algorithm.h"
#include "LinkedList.h"

int main() {

    LinkedList<int>* graph = new LinkedList<int>();

    graph->addBack(10);
    graph->addBack(20);
    graph->addBack(30);


//
//    Algorithm * d = new Search();
//    for(int i = Algorithm::BUBBLE; i != Algorithm::LAST;i++)
//    {
//        d->select(i);
//        d->execute();
//        d->stats();
//    }
//    //d->display();
//    d->save();

    return 0;
}