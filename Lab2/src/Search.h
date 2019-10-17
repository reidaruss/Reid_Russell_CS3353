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

    chrono::duration<double> bfsTime;
    chrono::duration<double> bfsTimeMat;
    chrono::duration<double> dfsTime;
    chrono::duration<double> dfsTimeMat;


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

// FOR THE PROGRAM
// TODO : command line arguments
// TODO : BFS, DFS, Dijkstra, A*
//          i. Iterative And Recursive
//          ii. Adjacency List and Matrix
// TODO : Algorithm::Stats should now output the following information in an easy to read format
//          o Algorithm Name
//          o Returned Path
//          o Number of nodes in returned path o Total Cost of path
//          o Total distance of path
//          o Number of nodes explored in path o Execution time to find path
// TODO : In main.cpp, loop through all algorithms and data sets to collect the performance timing.
//  Your main.cpp should look similar to


// FOR THE REPORT
// TODO :Randomly select source and destination nodes from selected graph
// TODO :Perform search from srcàdest on both adjacency list and matrix for each of the coded
//  algorithms, but keep results separate as they will compared against each other
// TODO :Collect following stats:
//  i. Number of nodes in path returned ii. Number of nodes explored
//  iii. Total time of execution
//  iv. Total Distance of path
//  v. For A* only: execute using a heuristic that combines cost with distance
//      1. F(n) = distance ( 1 + cost)
// TODO : For each test normalize results so they can be compared
// TODO : Perform test 100 times and record both raw and normalized values into output file, Each
//  algorithm should be tested on the same randomly selected 100 src/dest points.
// TODO : Average all execution stats for each graph set and place into a summary table
// TODO : You should have a summary table for the following combinations for each graph set provided
//      a. SourceàDestination, Adjacency Matrix
//      b. SourceàDestination, Adjacency List
// TODO : Create a plot for each of the performance metrics, where X axis is the graph set and Y axis is
//  the metric value. Each plot should have each algorithm plotted. There should be a total of 4 plots
//  (1 for each metric collected (i.e. Nodes in Path, Nodes Explored, Exe time, Distance))
// TODO : Submit all tables and graphs in nicely formatted report in word. Which includes a writeup explaining
//  results and differences between algorithms if any exist. Also provide the raw excel and data files used to create
//  the charts and tables.

// TODO : Submit inside of your class git repo, it folder Lab2/src/.

