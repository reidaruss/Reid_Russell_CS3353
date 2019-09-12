#include "insertion.h"

Insertion::Insertion()
{

}

//Perform insertion sort
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

//Used for debugging
void Insertion::printArray(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

//Runs insertion sort and returns the runtime while also returning the sorted vector by reference to Sort::execute()
chrono::duration<double> Insertion::execute(vector<int>& arr)
{
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    insertionSort(arr);
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    //printArray(arr);
    chrono::duration<double> time = chrono::duration_cast<chrono::duration<double>>(t2-t1);
    return time;
}
