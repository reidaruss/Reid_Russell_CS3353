
#include "Neighbor.h"


Neighbor::Neighbor(std::vector<Node> n)
{
    path = n;
    pathSize = path.size();
    calcDist();
}

bool Neighbor::operator==(const Neighbor &rhs)
{
    const Neighbor lhs = *this;
    for(int i = 0; i < path.size(); i++)
    {
        if(lhs.path[i].getId() != rhs.path[i].getId())
            return false;
    }
    return true;
}

void Neighbor::calcDist() {
    float distance = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        std::vector<float> posA = path[i].getPos();
        std::vector<float> posB = path[i + 1].getPos();
        float tempDist = 0;
        tempDist = std::sqrt(std::pow(posB[0] - posA[0], 2) + std::pow(posB[1] - posA[1], 2)
                             + std::pow(posB[2] - posA[2], 2));
        distance += tempDist;
    }
    dist = distance;
}

void Neighbor::printPath()
{
    for(int i = 0; i < path.size(); i++)
    {
        std::cout << path[i].getId() << " ";
    }
    std::cout << "Distance: " << dist;
    std::cout << std::endl;
}