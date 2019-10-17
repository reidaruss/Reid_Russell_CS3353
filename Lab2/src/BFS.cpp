//
// Created by Reid Russell on 9/24/19.
//

// Partly inspired by: https://www.geeksforgeeks.org/shortest-path-unweighted-graph/ but far from the same

#include "BFS.h"

using namespace std;

BFS::BFS(int s, int d)
{
    start = s;
    destination = d;
}



vector<Path> BFS::BFSAdjList(AdjacencyList<Path>* list, int size)
{
    depth = 1;

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

            for(int j = 0; j < list->getInnerSize(i); j++) {
                if (list->getAt(i, j)->getDest() == destination) {
                    pathToGoal.push_back(*list->getAt(i, j));
                    return pathToGoal;
                }
            }
            for(int j = 0; j < list->getInnerSize(i); j++) {
                    myQueue.push(*list->getAt(i,j));
                    //pathToGoal.push_back(*list->getAt(i,j));
            }
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
        pathToGoal.push_back(s);

        //cout << s << " ";
        myQueue.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        int index = list->findIndex(s.getDest());
        for(int i = 0; i< list->getInnerSize(index); i++)
        {
            if (list->getAt(index, i)->getDest() == destination) {
                pathToGoal.push_back(*list->getAt(index, i));
                return getShortestPath();
            }


            int vIndex = list->getAt(index, i)->getDest() - 1; //The destination int -1 to get the 0 index value
            if (!visited[vIndex]) // check if the destination node has been visited//
            {
                visited[vIndex] = true;
                myQueue.push(*list->getAt(index, i)); //get the first path in the new src index and push onto queue
            }


        }

    }

}

vector<Path>  BFS::getShortestPath()
{
    vector<Path> tempPath; //will be the shortest path backwards
    vector<Path> path;  //will be the shortest path
    tempPath.push_back(pathToGoal[pathToGoal.size()-1]); //push destination node
    int i = pathToGoal.size()-1; //upper bound is the back of the pathToGoal vector
    //int j = 0;
    if(pathToGoal.size() == 2)  //If the pathToGoal is only 2 then that is the shortest path
        return pathToGoal;
    while(i>= 1) {                  //Here we start at the back and loop from the beginning until the
        for(int j = 0; j < i; j++)  //path.destination from the front (j) = path.src from the back (i)
        {                           //Then set i(back) = j(front) and keep going from j = 0 to i
         if(pathToGoal[i].getSrc() == pathToGoal[j].getDest()) {
             tempPath.push_back(pathToGoal[j]);
             i = j;
             break;
         }
        }
    }

    //Path is backwards so flip it and return
    for(int i = tempPath.size()-1; i >=0 ; i--)
    {
        path.push_back(tempPath[i]);
    }



    return path;
}