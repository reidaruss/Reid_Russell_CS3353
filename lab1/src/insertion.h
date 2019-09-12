#ifndef INSERTION_H
#define INSERTION_H

#include <vector>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Insertion
{
public:
    Insertion();

    void insertionSort(vector<int>& arr);
    void printArray(vector<int> arr);
    void execute(vector<int> arr);

};

#endif // INSERTION_H
