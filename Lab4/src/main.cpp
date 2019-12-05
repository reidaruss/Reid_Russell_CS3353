//
// Created by Reid Russell on 11/28/19.
//

#include <deque>
#include <iostream>
#include "Algorithm.h"
#include "TSP.h"

int main() {
    std::srand(std::time(0));




    //Please place test graphs in sampleGraphs and modify filePaths with the desired graphs.
    std::string filePaths[] = {"pos.txt","pos5.txt","pos6.txt","pos7.txt","pos8.txt","pos9.txt","pos10.txt","pos11.txt","pos12.txt" };
    //std::string filePaths[] = {"../src/sampleGraphs/pos9.txt"};
    //std::string filePaths[] = {"graph22.txt","graph23.txt","graph24.txt","graph25.txt","graph26.txt","graph27.txt","graph28.txt","graph29.txt","graph30.txt","graph31.txt","graph32.txt","graph33.txt"};

    for(int j = 0; j < 9; j++) {
        Algorithm * d = new TSP();

        std::cout << "File: " << filePaths[j] << std::endl;
        d->load(filePaths[j]);
        for (int i = Algorithm::GA; i != Algorithm::LAST; i++) {
            d->select(i);
            d->execute();
            d->printSolution();
        }
        delete d;
    }




    return 0;
}