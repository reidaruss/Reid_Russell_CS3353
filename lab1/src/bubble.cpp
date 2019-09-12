#include "bubble.h"


Bubble::Bubble()
{

}

void Bubble::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

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

void Bubble::printArray(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

void Bubble::execute(vector<int> arr)
{
    bubbleSort(arr);
    //printArray(arr);
}
