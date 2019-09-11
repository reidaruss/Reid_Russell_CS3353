#include "datagen.h"
#include "bubble.h"
#include "insertion.h"

//remove
#include <fstream>
#include <vector>
//remove

int main()
{

    //datagen data;
    //data.execute();

    //REMOVE
    ifstream infile;
    //infile.open("../lab1/data/unsorted/thousand_random.txt");
    //infile.open("../lab1/data/unsorted/thousand_partUni.txt");
    //infile.open("../lab1/data/unsorted/thousand_partRand.txt");
    //infile.open("../lab1/data/unsorted/thousand_reverse.txt");
    int size;
    vector<int> arr;
    infile >> size;
    for(int i = 0; i < size; i++)
    {
        int num;
        infile >> num;
        arr.push_back(num);
    }
    cout << "BUBBLE:::::::::" <<endl;
    Bubble b;
    b.execute(arr);
    cout << "INSERTION::::::::::::::::::::::::::::::::::::::::" << endl;
    Insertion i;
    i.execute(arr);
    //REMOVE

    return 0;
}


