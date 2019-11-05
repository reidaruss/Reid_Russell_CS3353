//
// Created by Reid Russell on 10/31/19.
//

#include "fileIn.h"


void fileIn::readFile()
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
            Node n = stoi(item);
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

}

void fileIn::printNodes()
{
    for(int i = 0; i < nodes.size(); i++)
    {
        nodes[i].print();
    }
}