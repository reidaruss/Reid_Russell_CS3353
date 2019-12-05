//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_FILE_H
#define LAB4_FILE_H


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Node.h"


class file {
private:
    std::string fileName;
    std::vector<Node> nodes;
    std::vector<Node*> nodePs;

public:
    void setFileName(std::string file) {fileName = file;}
    void readFile();
    void setNodePs();

    std::vector<Node> getNodes() {return nodes;}
    std::vector<Node*> getNodePs() {return nodePs;}


    void writeCSV(std::vector<float> dists);
};

#endif //LAB4_FILE_H
