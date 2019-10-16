//
// Created by Reid Russell on 10/16/19.
//

#include "Path.h"



Path::Path(ListNode<int> *& source, ListNode<int> *& destination)
{
    src = source;
    dest = destination;
    weight = 0;
}