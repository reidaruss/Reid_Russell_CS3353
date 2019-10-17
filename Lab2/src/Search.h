//
// Created by Reid Russell on 9/24/19.
//

#ifndef LAB2_SEARCH_H
#define LAB2_SEARCH_H

#include "algorithm.h"
#include "LinkedList.h"
#include "AdjacencyList.h"
#include "Path.h"
#include "BFS.h"
#include "DFS.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>
#include <random>
#include<cstdlib>
#include<ctime>


using namespace std;

class Search :public Algorithm{
private:
    int searchAlgo;
    AdjacencyList<Path> graph;
    vector<ListNode<int> > nodes;
    vector<vector<float> > adjMatrix;
    vector<string> fileNames;
    bool loadedF = false;

    vector<Path> bfsPath;
    vector<Path> bfsPathMat;
    vector<Path> dfsPath;
    vector<Path> dfsPathMat;
    vector<Path> dkstra;

    chrono::duration<double> bfsTime;
    chrono::duration<double> bfsTimeMat;
    chrono::duration<double> dfsTime;
    chrono::duration<double> dfsTimeMat;
    chrono::duration<double> dkstraTime;

    bool testGen = false;
    vector<int> testCases;
    vector<int> numNodes;
    vector<int> numPath;
    vector<int> numPathMat;
    vector<chrono::duration<double> > totTime;
    vector<chrono::duration<double> > totTimeMat;
    vector<float> totDist;




public:
    Search();

    void load(string filePath);
    void execute(int start, int end);
    void display();
    void save();
    void select(int n);
    void configure();
    void stats();
    void log();
    void reportTests();
};


#endif //LAB2_SEARCH_H


