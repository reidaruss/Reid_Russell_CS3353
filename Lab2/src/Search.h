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


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <sstream>


using namespace std;

class Search :public Algorithm{
private:
    int searchAlgo;
    AdjacencyList<Path> graph;
    vector<ListNode<int> > nodes;

    vector<vector<int> > adjMatrix;


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
};


#endif //LAB2_SEARCH_H
