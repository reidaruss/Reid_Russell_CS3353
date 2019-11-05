#include <iostream>
#include "fileIn.h"
int main() {

//    Node n(1);
//    std::vector<float> v;
//    v.push_back(1.23);
//    v.push_back(3.45);
//    v.push_back(4.112);
//    n.setPos(v);


//    for(int i = 0; i < n.getPos().size(); i++)
//    {
//        std::cout << n.getPosAt(i) << std::endl;
//    }

    fileIn f("../pos.txt");
    f.readFile();
    f.printNodes();



    return 0;
}