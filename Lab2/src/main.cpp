#include <iostream>
#include "Search.h"
#include "algorithm.h"
#include "LinkedList.h"
#include "AdjacencyList.h"


// TODO : Figure out Adj matrix, build from input
// TODO : MAKE SURE TO REFERENCE BFS DFS DIJSTRA AND A* AND MAKE SURE EACH TAKES IN MATRIX AND LIST AND RETURNS PATH FROM START TO DEST
// TODO : Put some effort into the report



int main() {


    Search s;
    s.load("../SampleGraph/graph.txt");
    s.load("../SampleGraph/weights.txt");
    s.load("../SampleGraph/positions.txt");
    //s.display();
    s.execute(1,15);

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