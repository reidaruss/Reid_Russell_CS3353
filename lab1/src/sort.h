#ifndef SORT_H
#define SORT_H
#include "algorithm.h"

#include "insertion.h"
#include "merge.h"
#include "bubble.h"

#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

class Sort :public Algorithm
{
private:
    int sortAlgo;
    vector<string> fileNames;
    vector<int> data;
    vector<chrono::duration<double>> time;
    vector<int> big_data;



public:
    Sort();

    void load(string filePath);
    void execute();
    void display();
    void save();
    void select(int n);
    void configure();
    void stats();
    void log();
};

#endif // SORT_H
