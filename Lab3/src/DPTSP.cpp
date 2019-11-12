//
// Created by Reid Russell on 11/5/19.
//
// Referenced this video: https://codingblocks.com/resources/travelling-salesman/
//
//
//

#include "DPTSP.h"

dynamicProgTSP::dynamicProgTSP(std::vector<Node>* nList)
{
    nodes = *nList;
    tCost = 0;
    subtrees = std::vector<std::vector<float>> ((00000001<<nodes.size()) -1, std::vector<float> (nodes.size(),-1));
    dist = std::vector<std::vector<float>> (nodes.size(), std::vector<float> (nodes.size(),-1));
}

void dynamicProgTSP::calcDist()
{
    for(int i = 0; i < nodes.size(); i++)
    {
        std::vector<float> posA = nodes[i].getPos();
        for(int j = i; j < nodes.size(); j++)
        {
            if(i == j) {
                dist[i][j] = 0;
                continue;
            }
            else
            {
                std::vector<float> posB = nodes[j].getPos();
                dist[i][j] =  std::sqrt(std::pow(posB[0]-posA[0],2) + std::pow(posB[1]-posA[1],2)
                                        + std::pow(posB[2]-posA[2],2));
                dist[j][i] = dist[i][j];
            }
        }
    }
}




float dynamicProgTSP::tsp(int visited, int pos) {

    //Check if we have visited all of the nodes and if so return the distance from the current node to the starting node.
    if (visited == (00000001 << nodes.size()) - 1) {
        return dist[pos][0];
    }

    //Check if an shortest path for this subtree has already been found, if so go ahead and pass back that minDist.
    // This is what speeds up the program so much, it does not recalculate the minDist for a subtree and therefore
    // does allot less iterations.
    if (subtrees[visited][pos] != -1) {
        return subtrees[visited][pos];
    }

    //Set to large number so that first comparison always assigns nextDist to minDist and dont have to add another
    // if statement. This will cause problems if the total distance for a graph gets above this number.
    float minDist = 99999999;

    int nNode; //nNode will be assigned to the next node(index) every time newAns < current minDist.
            // Once the for loop ends (best subtree found) the node pertaining to that index is pushed onto path
            // and minDist is pushed onto minDists. This is to create a correlation between a subtree's minDist
            // and the next node (their indexes will be the same). These are used to construct the shortest path in
            // constructPath() after the total minDist is found.

    //Loop through and check if all of the nodes have been visited, when one hasn't, get a new distance of
    // current position to next node + the minimum distance of the next node's subtree. If the new distance is
    // less than the old minDist, a shorter path through the subtree has been found so we assign minDist to nextDist
    // and nNode to next. After the loop ends both are pushed onto parallel vectors so that they track each other.
    for (int next = 0; next < nodes.size(); next++) {
        if ((visited & (1 << next)) == 0) {
            float nextDist = dist[pos][next] + tsp(visited | (1 << next), next);
            if (nextDist < minDist) {
                minDist = nextDist;
                nNode = next;
            }
        }
    }

    minDists.push_back(minDist);
    path.push_back(nodes[nNode]);

    // Assign the position of visited(state) and pos to minDist so that in that state we know the shortest distance
    // for the rest of the subtree. Return minDist so that the value gets passed back recursively.
    return subtrees[visited][pos] = minDist;
}

std::vector<Node> dynamicProgTSP::constructPath()
{
    //Will end up being the final path
    std::vector<Node> p;

    //Initial position, distance and setting visited to the first node.
    int pos = 0;
    float dist = 0;
    int visited = 1;

    //Loop through the path
    for(int i = 0; i < path.size(); i++)
    {
        p.push_back(nodes[pos]);
        dist = subtrees[visited][pos];
        for(int j = minDists.size()-1; j > 0; j--)
        {
            if(minDists[j] == dist)
            {
                pos = path[j].getId()-1;
                break;
            }

        }
        visited = (visited | (1<< pos));

        if(visited == (1 << nodes.size()) - 1) {
            p.push_back(nodes[pos]);
            break;
        }
    }

    p.push_back(nodes[0]);
    return p;
}

void dynamicProgTSP::run()
{
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();


    calcDist();
    int mask = 00000001;
    std::vector<Node> p;
    std::vector<Node> subPath;
    tCost = tsp(mask,0, p);
    std::vector<Node> fPath = constructPath();

    std::cout << "DP: " << std::endl;
    std::cout << "Cost of path: " << tCost << std::endl;
    for(int i = 0; i < fPath.size(); i++)
    {
        std::cout << fPath[i].getId() << "->";
    }
    std::cout << std::endl;


    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);

}



