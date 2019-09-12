#ifndef BUBBLE_H
#define BUBBLE_H

#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

class Bubble
{
public:
    Bubble();

    void swap(int *xp, int *yp);
    void bubbleSort(vector<int>& arr);
    void printArray(vector<int>& arr);
    chrono::duration<double> execute(vector<int> arr);
};

#endif // BUBBLE_H
