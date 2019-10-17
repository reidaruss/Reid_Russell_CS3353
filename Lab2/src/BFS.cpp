//
// Created by Reid Russell on 9/24/19.
//

#include "BFS.h"

using namespace std;

BFS::BFS(int s, int d)
{
    start = s;
    destination = d;

}


vector<Path> BFS::BFSAdjList(AdjacencyList<Path>* list, int size)
{

    // Mark all the vertices as not visited
    bool *visited = new bool[size];
    for(int i = 0; i < size; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue<Path> myQueue;

    // Mark the current node as visited and enqueue it
    visited[start-1] = true;
    //Queue.push_back(start);
    for(int i = 0; i < list->getSize(); i++)
    {
        if(list->getAt(i,0)->getSrc() == start)
        {
            myQueue.push(*list->getAt(i,0));
            break;
        }

    }

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    //list<int>::iterator i;

    while(!myQueue.empty())
    {
        vector<Path> tempPaths;
        // Dequeue a vertex from queue and print it
        Path s = myQueue.front();

        //cout << s << " ";
        myQueue.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        int index = list->findIndex(s.getSrc());
        for(int i = 0; i< list->getInnerSize(index); i++)
        {
            if(list->getAt(index,i)->getDest() == destination)
            {
                pathToGoal.push_back(*list->getAt(index,i));
                return pathToGoal;
            }


            int vIndex = list->getAt(index,i)->getDest() -1; //The destination int -1 to get the 0 index value
            if(!visited[vIndex]) // check if the destination node has been visited
            {
                visited[vIndex] = true;
                pathToGoal.push_back(*list->getAt(list->findIndex(vIndex + 1), 0));

                myQueue.push(*list->getAt(list->findIndex(vIndex + 1), 0)); //get the first path in the new src index and push onto queue
            }
        }

    }

}