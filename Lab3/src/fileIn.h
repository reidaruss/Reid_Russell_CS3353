//
// Created by Reid Russell on 10/31/19.
//

#ifndef LAB3_FILEIN_H
#define LAB3_FILEIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Node.h"


class fileIn {
private:
    std::string fileName;
    std::vector<Node> nodes;


public:
    fileIn(std::string file) {fileName = file;}

    void readFile();
    void printNodes();
};


#endif //LAB3_FILEIN_H
