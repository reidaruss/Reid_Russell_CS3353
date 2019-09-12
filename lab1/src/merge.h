#ifndef MERGE_H
#define MERGE_H

#include <string>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Merge
{
public:
    Merge();

    void merge(vector<int>& arr,int p, int q, int r);
    void mergeSort(vector<int>& arr, int p, int r);
    void print(vector<int>& arr);
    chrono::duration<double> execute(vector<int>& arr);

};

#endif // MERGE_H
