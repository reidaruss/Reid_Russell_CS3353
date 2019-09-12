#ifndef SORT_H
#define SORT_H
#include "algorithm.h"
#include "bubble.h"
#include "insertion.h"
#include "merge.h"

class Sort :public Algorithm
{

public:
    Sort();

    void load(string filename);
    void execute();
    void display();
};

#endif // SORT_H
