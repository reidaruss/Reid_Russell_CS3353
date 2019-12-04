//
// Created by Reid Russell on 11/23/2019.
//
#include "Node.h"

Node::Node()
{

}



// Setting each position in position vector.
void Node::setPos(std::vector<float> pos)
{
    for(int i = 0; i < pos.size(); i ++)
    {
        position.push_back(pos[i]);
    }
}

