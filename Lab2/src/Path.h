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

    float weight;

public:

    Path();
    void setPath(ListNode<int> *& source, ListNode<int> *& destination);
    int getSrc(){ return src->getPayload();}
    int getDest(){ return dest->getPayload();}
    float getWeight(){return weight;}
    void setWeight(float w) { weight = w;}

    void printPath();


};


#endif //LAB2_PATH_H
