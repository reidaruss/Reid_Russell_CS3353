//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_NODE_H
#define LAB4_NODE_H

#include <iostream>
#include <vector>


class Node {
private:
    int nodeId;
    std::vector<float> position;

public:
    Node();

    void setPos(std::vector<float> pos);
    void setId(int id) {nodeId = id;}
    int getId()const {return nodeId;}
    std::vector<float> getPos() {return position;}
    float getPosAt(int i) {return position[i];}

};


#endif //LAB4_NODE_H