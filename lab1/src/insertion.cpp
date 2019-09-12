#include "insertion.h"

Insertion::Insertion()
{

}

void Insertion::insertionSort(vector<int> &arr)
{
    int key, j;
    for(int i = 0; i < arr.size(); i ++)
    {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j + 1] = key;
    }
}

void Insertion::printArray(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

void Insertion::execute(vector<int> arr)
{
    insertionSort(arr);
    //printArray(arr);
}
