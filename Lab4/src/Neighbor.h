//
// Created by Reid Russell on 12/4/19.
//

#ifndef LAB4_NEIGHBOR_H
#define LAB4_NEIGHBOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

#include "Node.h"

class Neighbor {
private:
    std::vector<Node> path;
    float dist;
    int pathSize;

public:
    Neighbor(){dist = 0; pathSize = 0;}
    bool operator ==(const Neighbor& rhs);
    Neighbor(std::vector<Node> n);

    void calcDist();

    Node getAt(int index) {return path[index];}
    std::vector<Node> getPath() {return path;}
    float getDist(){return dist;}
    int getSize(){return pathSize;}

    void setPath(std::vector<Node> n){path = n; calcDist(); pathSize = path.size();}
    void printPath();

};


#endif //LAB4_NEIGHBOR_H
