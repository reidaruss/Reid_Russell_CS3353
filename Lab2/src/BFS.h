//
// Created by Reid Russell on 9/24/19.
//

#ifndef LAB2_BFS_H
#define LAB2_BFS_H

#include "AdjacencyList.h"
#include "Path.h"
#include "LinkedList.h"

#include <iostream>
#include <queue>



class BFS {
private:
    int size;   //number of nodes
    //Path goalPath;
    int start, destination;
    vector<Path> pathToGoal;

public:

    BFS(int s, int d);

    vector<Path> BFSAdjList(AdjacencyList<Path>* list, int size);

};


#endif //LAB2_BFS_H
