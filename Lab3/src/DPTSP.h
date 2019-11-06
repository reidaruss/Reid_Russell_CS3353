//
// Created by Reid Russell on 11/5/19.
//

#ifndef LAB3_DPTSP_H
#define LAB3_DPTSP_H

#include <iostream>
#include <vector>
#include <algorithm>


#include "Node.h"


class dynamicProgTSP {

private:
    std::vector<Node> nodes;

public:
    dynamicProgTSP(std::vector<Node>* nList);

    void run();

};


#endif //LAB3_DPTSP_H
