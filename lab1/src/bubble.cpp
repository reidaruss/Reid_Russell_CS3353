#include "bubble.h"


Bubble::Bubble()
{

}

//Performs the swapping for bubble sort
void Bubble::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Performs the comparisons for bubble sort
void Bubble::bubbleSort(vector<int>& arr)
{
    int i , j;
    for(i = 0; i < arr.size()-1;i++)
    {
        for(j = 0;j <arr.size()-i-1;j++)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

//Used for debuggin purposes
void Bubble::printArray(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

//Runs bubble sort and returns the runtime while also returning the sorted vector by reference to Sort::execute()
chrono::duration<double> Bubble::execute(vector<int>& arr)
{
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    bubbleSort(arr);
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    //printArray(arr);

    chrono::duration<double> time = chrono::duration_cast<chrono::duration<double>>(t2-t1);
    return time;
}
