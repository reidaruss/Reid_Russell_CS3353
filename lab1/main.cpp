#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;



void fileOut()
{

}

void randomize(int arr[], int SIZE)
{

    for(int i = 0; i < SIZE; i ++)
    {
        int num = rand() % SIZE;
        arr[i] = num;
    }
    for(int i = 0; i < SIZE; i ++)
    {
        cout << arr[i] << endl;
    }

}

void reverse(int arr[], int SIZE)
{
    int newarr[SIZE];
    int j = 0;
    for(int i = SIZE-1; i >= 0; i --)
    {
        newarr[j] = arr[i];
        j++;
    }
    for(int i = 0; i < SIZE; i ++)
    {
        arr[i] = newarr[i];
    }

}



void ten()
{
    int SIZE = 10;
    int nums[SIZE];

    for(int i = 0; i < SIZE; i ++)
    {
        nums[i] = i+1;
    }
    //randomize(nums,SIZE);
    //reverse(nums,SIZE);
    cout << "Tens Done" << endl;
}

void thousand()
{
    int SIZE = 1000;
    int nums[SIZE];

    for(int i = 0; i < SIZE; i ++)
    {
        nums[i] = i+1;
    }
    //randomize(nums,SIZE);
    //reverse(nums,SIZE);
    cout << "Thousand" << endl;
}

void tenThousand()
{
    int SIZE = 10000;
    int nums[SIZE];

    for(int i = 0; i < SIZE; i ++)
    {
        nums[i] = i+1;
    }
    //reverse(nums,SIZE);
    cout << "Ten Thousand" << endl;
}

void hundThousand()
{
    int SIZE = 100000;
    int nums[SIZE];

    for(int i = 0; i < SIZE; i ++)
    {
        nums[i] = i+1;
    }
    //reverse(nums,SIZE);
    cout << "Hund Thousand Done" << endl;
}



int main()
{
    ten();
    thousand();
    tenThousand();
    hundThousand();

    return 0;
}


