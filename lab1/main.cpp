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
        for(int j = 0; j < 16; j++)
        {
            //driver->load();
            driver->execute();
            driver->stats();
        }
    }


    return 0;
}


