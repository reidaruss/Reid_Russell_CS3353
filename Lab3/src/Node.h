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
    Node(int id);
    void setPos(std::vector<float> pos);

    int getId() {return nodeId;}
    std::vector<float> getPos() {return position;}
    float getPosAt(int i) {return position[i];}

    void print();
};


#endif //LAB3_NODE_H
