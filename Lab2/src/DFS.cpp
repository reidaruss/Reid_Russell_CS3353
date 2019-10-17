//
// Created by Reid Russell on 9/24/19.
//

#include "DFS.h"

using namespace std;

DFS::DFS(int s, int d)
{
    start = s;
    destination = d;
}



vector<Path> DFS::DFSAdjList(AdjacencyList<Path>* list, int size) {
    depth = 1;

    // Mark all the vertices as not visited
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;

    // Create a stack for DFS
    stack<Path> myStack;

    // Mark the current node as visited and enqueue it
    visited[start - 1] = true;
    // Queue.push_back(start);
    int index = list->findIndex(start);
    for (int i = 0; i < list->getInnerSize(index); i++) {


        if (list->getAt(index, i)->getDest() == destination) {
            pathToGoal.push_back(*list->getAt(index, i));
            return pathToGoal;
        }

        myStack.push(*list->getAt(index, i));

    }



    int indx = list->findIndex(start);
    myStack.push(*list->getAt(indx, 0));


    while(!myStack.empty())
    {
        vector<Path> tempPaths;
        // Dequeue a vertex from queue and print it
        Path s = myStack.top();
        pathToGoal.push_back(s);

        //cout << s << " ";
        myStack.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        int index = list->findIndex(s.getDest());
        for(int i = 0; i< list->getInnerSize(index); i++)
        {
            if (list->getAt(index, i)->getDest() == destination) {
                pathToGoal.push_back(*list->getAt(index, i));
                return pathToGoal;
            }


            int vIndex = list->getAt(index, i)->getDest() - 1; //The destination int -1 to get the 0 index value
            if (!visited[vIndex]) // check if the destination node has been visited//
            {
                visited[vIndex] = true;
                myStack.push(*list->getAt(index, i)); //get the first path in the new src index and push onto stack
            }


        }

    }

}

vector<Path>  DFS::getShortestPath()
{
    vector<Path> tempPath; //will be the shortest path backwards
    vector<Path> path;  //will be the shortest path
    tempPath.push_back(pathToGoal[pathToGoal.size()-1]); //push destination node
    int i = pathToGoal.size()-1; //upper bound is the back of the pathToGoal vector
    //int j = 0;
    if(pathToGoal.size() == 2)  //If the pathToGoal is only 2 then that is the shortest path
        return pathToGoal;
    while(i> 1) {                  //Here we start at the back and loop from the beginning until the
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

vector<Path>  DFS::getShortestPathMatrix()
{
    vector<Path> tempPath; //will be the shortest path backwards
    vector<Path> path;  //will be the shortest path
    tempPath.push_back(pathToGoalMat[pathToGoalMat.size()-1]); //push destination node
    int i = pathToGoalMat.size()-1; //upper bound is the back of the pathToGoal vector
    //int j = 0;
    if(pathToGoalMat.size() == 2)  //If the pathToGoal is only 2 then that is the shortest path
        return pathToGoalMat;
    while(i> 1) {                  //Here we start at the back and loop from the beginning until the
        for(int j = 0; j < i; j++)  //path.destination from the front (j) = path.src from the back (i)
        {                           //Then set i(back) = j(front) and keep going from j = 0 to i
            if(pathToGoalMat[i].getSrcInt() == pathToGoalMat[j].getDestInt()) {
                tempPath.push_back(pathToGoalMat[j]);
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


vector<Path> DFS::DFSMatrix( vector<vector<float> > *matrix, int size) {
    //depth = 1;
    float zero = 0;
    vector<vector<float> > mat = *matrix;


    // Mark all the vertices as not visited
    bool *visitedMat = new bool[size];
    for (int i = 0; i < size; i++)
        visitedMat[i] = false;

    // Create a queue for BFS
    stack<Path> myStack;

    // Mark the current node as visited and enqueue it
    visitedMat[start - 1] = true;
    //Queue.push_back(start);
    if (mat[start - 1][destination - 1] != 0) {
        Path p;
        p.setIntPath(start, destination);
        pathToGoalMat.push_back(p);
        return pathToGoalMat;
    }
    for (int i = 0; i < size; i++) {
        if (mat[start - 1][i] != 0) {
            Path p;
            p.setIntPath(start, i + 1);
            myStack.push(p);
            //visited[i] = true;
        }

    }



    // vertices of a vertex
    //list<int>::iterator i;

    while (!myStack.empty()) {
        // Dequeue a vertex from queue and print it
        Path s = myStack.top();
        pathToGoalMat.push_back(s);
        myStack.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        int index = s.getDestInt() - 1;
        for (int i = 0; i < size; i++) {
            if (mat[index][i] != zero) {
                if (i + 1 == destination) {
                    Path p;
                    p.setIntPath(s.getDestInt(), i + 1);
                    pathToGoalMat.push_back(p);
                    return pathToGoalMat;
                }

                int vIndex = s.getDestInt() - 1; //The destination int -1 to get the 0 index value
                if (!visitedMat[vIndex]) // check if the destination node has been visited//
                {
                    visitedMat[vIndex] = true;
                    for (int j = 0; j < size; j++) {
                        if (mat[s.getDestInt()-1][j] != 0) {
                            if (!visitedMat[j]) {
                                Path p;
                                p.setIntPath(s.getDestInt(), j + 1);
                                myStack.push(p); //get the first path in the new src index and push onto queue
                            }
                        }
                    }

                }
            }
        }


    }

}
