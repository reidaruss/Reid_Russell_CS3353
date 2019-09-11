#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;



void fileOut()
{

}

void randomize(vector<int>& arr,int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        arr.push_back(i);
    }
    random_shuffle(arr.begin(), arr.end());
    

}

vector<int> reverse(int SIZE)
{
    vector<int> arr;
    int j = 0;
    for(int i = SIZE-1; i >= 0; i --)
    {
        arr.push_back(i);
        j++;
    }
    return arr;

}

vector<int> twentyEighty(int SIZE)
{
    vector<int> arr;
    int uni = SIZE * 0.2;
    for(int i = 0; i < uni; i++)
    {
        arr.push_back(i);
    }
    for(int i = uni; i < SIZE; i++)
    {
        arr.push_back(rand() % uni);
    }

    random_shuffle(arr.begin(), arr.end());
    return arr;
}

vector<int> thirtyRand(int SIZE)
{
    vector<int> arr;
    for(int i = 0; i < SIZE; i++)
    {
        int num = rand() % 100 + 1;
        if(num <= 30)
        {
            arr.push_back( rand() % SIZE);
        }
        else
        {
            arr.push_back(i);
        }
    }
    return arr;
}



void ten()
{
    int SIZE = 10;
    vector<int> nums;
    vector<int> rev;
    vector<int> partUni;
    vector<int> partRand;

    randomize(nums, SIZE);
    rev = reverse(SIZE);
    partUni = twentyEighty(SIZE);
    partRand = thirtyRand(SIZE);
    cout << "Tens Done" << endl;

}

void thousand()
{
    int SIZE = 1000;
    vector<int> nums;
    vector<int> rev;
    vector<int> partUni;
    vector<int> partRand;

    randomize(nums,SIZE);
    rev = reverse(SIZE);
    partUni = twentyEighty(SIZE);
    partRand = thirtyRand(SIZE);

    cout << "Thousand" << endl;
}

void tenThousand()
{
    int SIZE = 10000;
    vector<int> nums;
    vector<int> rev;
    vector<int> partUni;
    vector<int> partRand;


    randomize(nums,SIZE);
    rev = reverse(SIZE);
    partUni = twentyEighty(SIZE);
    partRand = thirtyRand(SIZE);
    cout << "Ten Thousand" << endl;
}

void hundThousand()
{
    int SIZE = 100000;
    vector<int> nums;
    vector<int> rev;
    vector<int> partUni;
    vector<int> partRand;


    randomize(nums,SIZE);
    rev = reverse(SIZE);
    partUni = twentyEighty(SIZE);
    partRand = thirtyRand(SIZE);
    cout << "Hund Thousand Done" << endl;
}



int main()
{
    srand(time(NULL));
    ten();
    thousand();
    tenThousand();
    hundThousand();

    return 0;
}


