#ifndef MERGE_H
#define MERGE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Merge
{
public:
    Merge();

    void merge(vector<int>& arr,int l, int m, int r);
    void swapVals(int& a, int& b);
    void mergeSort(vector<int>& arr, int l, int r);
    void print(vector<int>& arr);
    void execute(vector<int> arr);

};

#endif // MERGE_H
