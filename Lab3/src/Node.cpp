//
// Created by Reid Russell on 10/30/19.
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




