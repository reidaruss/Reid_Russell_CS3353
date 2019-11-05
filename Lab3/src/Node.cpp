//
// Created by Reid Russell on 10/30/19.
//

#include "Node.h"

Node::Node()
{

}

Node::Node(int id)
{
    nodeId = id;
}

void Node::setPos(std::vector<float> pos)
{
    for(int i = 0; i < pos.size(); i ++)
    {
        position.push_back(pos[i]);
    }
}

void Node::print()
{
    std::cout << "Node ID: " << nodeId << " Position: " << position[0] << "," << position[1] << "," << position[2];
    std:: cout << std::endl;
}

