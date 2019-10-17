#include <iostream>
#include "Search.h"
#include "algorithm.h"
#include "LinkedList.h"
#include "AdjacencyList.h"




// TODO : Figure out Adj matrix, build from input
// TODO : MAKE SURE TO REFERENCE BFS DFS DIJSTRA AND A* AND MAKE SURE EACH TAKES IN MATRIX AND LIST AND RETURNS PATH
//  FROM START TO DEST



int main() {


    Search s;
    s.select(0);
    s.execute(1,16);
    s.select(1);
    s.execute(1,16);

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