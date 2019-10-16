//
// Created by Reid Russell on 10/16/19.
//

#ifndef LAB2_PATH_H
#define LAB2_PATH_H

#include "LinkedList.h"

class Path {
private:
    ListNode<int> * src;
    ListNode<int> * dest;

    int weight;

public:

    Path(ListNode<int> *& source, ListNode<int> *& destination);
    int getSrc(){ return src->getPayload();}
    int getDest(){ return dest->getPayload();}
    int getWeight(){return weight;}
    void setWeight(int w) { weight = w;}


};


#endif //LAB2_PATH_H
