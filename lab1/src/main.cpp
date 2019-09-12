// Reid Russell
// CS 3353
// Lab 1 Sorting Algorithms
//
//Filepaths are in Sort constructor.
//
#include "datagen.h"
#include "algorithm.h"
#include "sort.h"


int main()
{

    //datagen data;
    //data.execute();

    Algorithm * d = new Sort();
    for(int i = Algorithm::BUBBLE; i != Algorithm::LAST;i++)
    {
        d->select(i);
        d->execute();
        d->stats();
    }
    //d->display();
    d->save();

    return 0;
}


