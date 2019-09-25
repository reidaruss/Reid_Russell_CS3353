#include <iostream>
#include "Search.h"
#include "algorithm.h"

int main() {

    Algorithm * d = new Search();
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