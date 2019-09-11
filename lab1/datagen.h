#ifndef DATAGEN_H
#define DATAGEN_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class datagen
{
public:
    datagen();
    void fileOut(string file_name,vector<int> arr);
    void randomize(vector<int>& arr,int SIZE);
    vector<int> reverse(int SIZE);
    vector<int> twentyEighty(int SIZE);
    vector<int> thirtyRand(int SIZE);
    void ten();
    void thousand();
    void tenThousand();
    void hundThousand();
    void execute();




};

#endif // DATAGEN_H
