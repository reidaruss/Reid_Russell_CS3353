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
#include <vector>
#include <string>



class BFS {
private:
    int size;   //number of nodes
    int start, destination;
    int depth;
    vector<Path> pathToGoal;
    vector<Path> pathToGoalMat;

public:

    BFS(int s, int d);

    vector<Path> BFSAdjList(AdjacencyList<Path>* list, int size);
    vector<Path> BFSMatrix( vector<vector<float> > *matrix, int size);

    vector<Path>  getShortestPath();
    vector<Path>  getShortestPathMatrix();


};


#endif //LAB2_BFS_H
