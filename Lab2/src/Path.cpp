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
    cout << "Source: " << src->getPayload() << " Destination: " << dest->getPayload() << endl;
}

void Path::printPathMat()
{
    cout << "Source: " << srcInt << " Destination: " << destInt << endl;
}