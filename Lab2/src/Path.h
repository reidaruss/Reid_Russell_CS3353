//
// Created by Reid Russell on 10/16/19.
//

#ifndef LAB2_PATH_H
#define LAB2_PATH_H

#include "LinkedList.h"
#include <math.h>

class Path {
private:
    ListNode<int> * src;
    ListNode<int> * dest;

    int srcInt;
    int destInt;

    float weight;
    float distance;

public:

    Path();
    void setPath(ListNode<int> *& source, ListNode<int> *& destination);
    int getSrc(){ return src->getPayload();}
    int getDest(){ return dest->getPayload();}
    float getWeight(){return weight;}
    void setWeight(float w) { weight = w;}

    int getSrcInt() {return srcInt;};
    int getDestInt(){return destInt;}
    void setIntPath(int s, int d){srcInt = s; destInt = d;}

    void setDistance();
    float getDistance(){return distance;}


    void printPath();
    void printPathMat();


};


#endif //LAB2_PATH_H
