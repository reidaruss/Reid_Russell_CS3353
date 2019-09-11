#include "merge.h"

Merge::Merge()
{

}

void Merge::swapVals(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Merge::merge(vector<int> &arr, int l, int m, int r)
{
    int nl;
    int nr;
    nl = m-l+1;
    nr = r-m;

    int left[nl];
    int right[nr];

    for(int i = 0; i < nl; i++)
    {
        left[i] = arr[l+i];
    }
    for(int i = 0; i < nr; i ++)
    {
        right[i] = arr[m+1+i];
    }
    int i = 0;
    int j = 0;
    int k = 1;

    while(i<nl && j<nr)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

}

void Merge::mergeSort(vector<int> &arr, int l, int r)
{
    int m;
    if(l < r)
    {
        m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void Merge::print(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

void Merge::execute(vector<int> arr)
{
    mergeSort(arr,0,arr.size()-1);
    print(arr);
}
