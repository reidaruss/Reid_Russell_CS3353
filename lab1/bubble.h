#ifndef BUBBLE_H
#define BUBBLE_H

#include <vector>
#include <iostream>

using namespace std;

class Bubble
{
public:
    Bubble();

    void swap(int *xp, int *yp);
    void bubbleSort(vector<int>& arr);
    void printArray(vector<int>& arr);
    void execute(vector<int> arr);
};

#endif // BUBBLE_H
