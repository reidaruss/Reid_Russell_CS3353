//
// Created by Reid Russell on 11/23/2019.
//

#include "file.h"
// Populate vector of nodes in order, then create vector of node pointers for next_permutation
void file::readFile()
{
    std::ifstream file;
    file.open(fileName);
    std::string line;
    std::string item;
    if (file.is_open())
    {
        while (!file.eof())
        {
            std::vector<float> pos;
            std::getline(file, line, '\n');  //get the node to assign position to
            std::istringstream iss(line);
            std::getline(iss, item, ',');
            Node n;
            n.setId(stoi(item));
            std::getline(iss, item, ',');
            float x = stof(item);
            pos.push_back(x);
            std::getline(iss, item, ',');
            float y = stof(item);
            pos.push_back(y);
            std::getline(iss, item, ',');
            float z = stof(item);
            pos.push_back(z);

            n.setPos(pos);
            nodes.push_back(n);


        }

    }
    file.close();

    setNodePs();

}


// Creates a vector of Node pointers to be used with next_permutation in brute force TSP
void file::setNodePs()
{
    for(int i = 0; i < nodes.size(); i++)
    {
        nodePs.push_back(&nodes[i]);
    }
}