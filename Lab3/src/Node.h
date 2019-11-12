//
// Created by Reid Russell on 10/30/19.
//

#ifndef LAB3_NODE_H
#define LAB3_NODE_H

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
    int getId() {return nodeId;}
    std::vector<float> getPos() {return position;}
    float getPosAt(int i) {return position[i];}

};


#endif //LAB3_NODE_H
