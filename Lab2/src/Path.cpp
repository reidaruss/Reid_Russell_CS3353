//
// Created by Reid Russell on 10/16/19.
//

#include "Path.h"

Path::Path()
{

}

void Path::setPath(ListNode<int> *& source, ListNode<int> *& destination)
{
    src = source;
    dest = destination;
    weight = 0;

}

void Path::printPath()
{
    cout <<  src->getPayload() << " --> " << dest->getPayload() ;
}

void Path::printPathMat()
{
    cout <<  srcInt << " --> " << destInt;
}

void Path::setDistance() {
    float x1 = src->getPos()[0];
    float x2 = dest->getPos()[0];
    float y1 = src->getPos()[1];
    float y2 = dest->getPos()[1];
    float z1 = src->getPos()[2];
    float z2 = src->getPos()[2];

    float a = x1 - x2;
    float b = y1 - y2;
    float c = z1 - z2;

    distance = sqrt((a*a)+(b*b)+(c*c));
}