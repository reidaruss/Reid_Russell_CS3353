//
// Created by Reid Russell on 9/24/19.
//

#ifndef LAB2_DFS_H
#define LAB2_DFS_H


#include "AdjacencyList.h"
#include "Path.h"
#include "LinkedList.h"

#include <iostream>
#include <stack>
#include <vector>
#include <string>



class DFS {
private:
    int size;   //number of nodes
    int start, destination;
    int depth;
    vector<Path> pathToGoal;
    vector<Path> pathToGoalMat;

public:

    DFS(int s, int d);

    vector<Path> DFSAdjList(AdjacencyList<Path>* list, int size);
    vector<Path> DFSMatrix( vector<vector<float> > *matrix, int size);

    vector<Path>  getShortestPath();
    vector<Path>  getShortestPathMatrix();


};
#endif //LAB2_DFS_H
