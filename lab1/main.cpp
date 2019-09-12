#include "datagen.h"
#include "algorithm.h"
#include "sort.h"
//remove

//remove

int main()
{

    //datagen data;
    //data.execute();

    //REMOVE

    //REMOVE
    Algorithm * driver = new Sort();
    for(int i = Algorithm::BUBBLE; i != Algorithm::LAST;i++)
    {
        driver->select(i);
        driver->execute();
        driver->stats();
    }


    return 0;
}


