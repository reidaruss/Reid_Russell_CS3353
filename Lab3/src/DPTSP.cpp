//
// Created by Reid Russell on 11/5/19.
//

#include "DPTSP.h"

dynamicProgTSP::dynamicProgTSP(std::vector<Node>* nList)
{
    nodes = *nList;
}

void dynamicProgTSP::calcDist()
{
    dist = std::vector<std::vector<float>> (nodes.size(), std::vector<float> (nodes.size(),-1));

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

int dynamicProgTSP::findMin(int index)
{
    float temp_min = -1;
    int min_index = -1;
    for(int i = 0; i < nodes.size(); i ++)
    {
        if(i == index)
            continue;
        else if(isVisited(nodes[i].getId()))
            continue;
        else{
            if(temp_min == -1)
            {
                temp_min = dist[index][i];
                min_index = i;
            }
            else if(dist[index][i] < temp_min)
            {
                temp_min = dist[index][i];
                min_index = i;
            }

        }
    }

    return min_index;
}

bool dynamicProgTSP::isVisited(int id)
{
    for(int i =0; i < visited.size(); i++)
    {
        if(visited[i] == id)
            return true;
    }

    return false;
}

void dynamicProgTSP::run()
{
    calcDist();


    path.push_back(nodes[0]);
    bool found = false;
    int next_node = findMin(0);
    visited.push_back(nodes[next_node].getId());
    path.push_back(nodes[next_node]);
    while(!found)
    {
        next_node = findMin(next_node);
        visited.push_back(nodes[next_node].getId());
        path.push_back(nodes[next_node]);
        if(visited.size() == nodes.size())
            found = true;
    }


//    float distance = 0;
//    for(int i = 0; i < nodes.size(); i++)
//    {
//
//    }


    for(int i = 0; i < path.size(); i++)
        std::cout << path[i].getId() << "->";
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
