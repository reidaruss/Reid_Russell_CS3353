#include "datagen.h"
#include "algorithm.h"
#include "sort.h"
//remove

//remove

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


    return 0;
}


