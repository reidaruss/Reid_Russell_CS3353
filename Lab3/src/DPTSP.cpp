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
//    subtrees = std::vector<std::vector<int>> (std::pow(nodes.size(), 2), std::vector<int> (nodes.size(),-1));

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

//int dynamicProgTSP::findMin(int index)
//{
//    float temp_min = -1;
//    int min_index = -1;
//    for(int i = 0; i < nodes.size(); i ++)
//    {
//        if(i == index)
//            continue;
//        else if(isVisited(nodes[i].getId()))
//            continue;
//        else{
//            if(temp_min == -1)
//            {
//                temp_min = dist[index][i];
//                min_index = i;
//            }
//            else if(dist[index][i] < temp_min)
//            {
//                temp_min = dist[index][i];
//                min_index = i;
//            }
//
//        }
//    }
//
//    return min_index;
//}

//bool dynamicProgTSP::isVisited(int id)
//{
//    for(int i =0; i < visited.size(); i++)
//    {
//        if(visited[i] == id)
//            return true;
//    }
//
//    return false;
//}

float dynamicProgTSP::tsp(int node, std::vector<bool> visited)
{
    std::vector<bool>  allNodes(nodes.size(), true);

    if(visited == allNodes)
    {
        return dist[node][0];
    }
    for(int i = 0; i < state.size(); i++)
    {
        if(state[i] == visited)
        {
            return subtrees[i];
        }
    }

    float minDist = -1;

    for(int i = 0; i < nodes.size(); i++)
    {
        if(visited[i] == false)
        {
            if(minDist == -1)
            {
                std::vector<bool> v = visited;
                v[i] = true;
                minDist = dist[node][i] + tsp( i , v);
            }
            else
            {
                std::vector<bool> v = visited;
                v[i] = true;
                int tempDist = dist[node][i] + tsp( i , v);
                minDist = fmin(minDist, tempDist);
            }
        }
    }

    subtrees.push_back(minDist);
    state.push_back(visited);
    return minDist;




}

void dynamicProgTSP::run()
{
    calcDist();

    std::vector<bool> visited(nodes.size(), false);
    visited[0] = true;
    tCost = tsp(0, visited);

    std::cout << "DP: " << std::endl;
    std::cout << "Cost of path: " << tCost << std::endl;
//    for(int i = 0; i < path.size(); i++)
//        std::cout << path[i].getId() << "->";
//    std::cout << std::endl;



    std::cout << std::endl;
//    for(int i = 0; i < nodes.size(); i++)
//    {
//        for(int j = 0; j < nodes.size(); j++)
//        {
//            std::cout << dist[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
}
