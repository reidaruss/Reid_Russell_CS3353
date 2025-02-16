#include "merge.h"

Merge::Merge()
{

}


//This function merges the seperated vector back together while performing the check for sorting.
void Merge::merge(vector<int> &arr, int p, int q, int r)
{
    int nl;
    int nr;
    nl = q-p+1;
    nr = r-q;
    int i,j;
    int left[nl];
    int right[nr];

    for(i = 0 ; i < nl; i++)
    {
        left[i] = arr[p+i];
    }
    for(j = 0; j < nr; j ++)
    {
        right[j] = arr[q+1+j];
    }
    i = 0;
    j = 0;
    int k;
    for(k = p; i<nl && j< nr; k++)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
    }

    while(i<nl)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j<nr)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

}

//Controls the higher level of merge sort
void Merge::mergeSort(vector<int> &arr, int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p+r)/2;            // q is midpoint
        mergeSort(arr,p,q);     //splitting vector
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);       //merging everything back together
    }
}

//Used for debugging purposes
void Merge::print(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

//Runs merge sort and returns the runtime while also returning the sorted vector by reference to Sort::execute()
chrono::duration<double> Merge::execute(vector<int>& arr)
{
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    mergeSort(arr,0,arr.size()-1);
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    //print(arr);
    chrono::duration<double> time = chrono::duration_cast<chrono::duration<double>>(t2-t1);
    return time;
}
