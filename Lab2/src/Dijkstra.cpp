//
// Created by Reid Russell on 9/24/19.
//

//Used as reference: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

#include "Dijkstra.h"

using namespace std;





vector<Path> Dijkstra::Djk(AdjacencyList<Path>* list, int size)
{
    vector<Path> path;     //For holding final path
    vector<float> distance; //For holding shortest distance
    bool usedSet[size];

    stack<Path> myQueue;
    //stack<float> dists;

    //distance.push_back(0);

    int index = list->findIndex(start);
    for(int i = 0; i < list->getInnerSize(index); i++)
    {
        if(list->getAt(index, i)->getDest() == end)
        {
            path.push_back(*list->getAt(index, i));
            return path;
        }
        list->getAt(index, i)->setDistance();
        distance.push_back( list->getAt(index, i)->getDistance());
    }


    float smallest = distance[index];
    int num = 0;
    for (int z = 0; z < distance.size(); z++) {
        if (distance[z] < smallest) {
            smallest = distance[z];
            num = z;
        }
    }

    myQueue.push(*list->getAt(list->findIndex(index), num));
    path.push_back(*list->getAt(list->findIndex(index), num));


    while(!myQueue.empty()) {
        Path s = myQueue.top();
        myQueue.pop();

        vector<float> dists;

        int index = list->findIndex(s.getDest());
        for(int i = 0; i < list->getInnerSize(index); i++)
        {
            if(list->getAt(index, i)->getDest() == end)
            {
                path.push_back(*list->getAt(index, i));
                return path;
            }
            list->getAt(index, i)->setDistance();
            dists.push_back( list->getAt(index, i)->getDistance());
        }


        float smallest = dists[index];
        int num = 0;
        for (int z = 0; z < dists.size(); z++) {
            if (dists[z] < smallest) {
                smallest = dists[z];
                num = z;
            }
        }

        myQueue.push(*list->getAt(list->findIndex(index), num));



    }

}


vector<Path> Dijkstra::DjkMatrix( vector<vector<float> > *matrix, int size)
{

}