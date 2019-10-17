//
// Created by Reid Russell on 9/24/19.
//

#ifndef LAB2_DIJKSTRA_H
#define LAB2_DIJKSTRA_H

#include "AdjacencyList.h"
#include "Path.h"
#include "LinkedList.h"

#include <iostream>
#include <vector>
#include <string>
#include <stack>
//#include<bits/stdc++.h>

class Dijkstra {

private:
    int start, end;
    vector<Path> pathToGoal;
    vector<Path> pathToGoalMat;

public:
    Dijkstra(int s, int e){start = s; end = e;}


    vector<Path> Djk(AdjacencyList<Path>* list, int size);
    vector<Path> DjkMatrix( vector<vector<float> > *matrix, int size);






};


#endif //LAB2_DIJKSTRA_H
