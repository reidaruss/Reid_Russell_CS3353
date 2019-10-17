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