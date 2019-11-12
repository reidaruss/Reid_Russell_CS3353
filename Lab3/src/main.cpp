
#include "Algorithm.h"
#include "TSP.h"

int main() {

    std::string filePaths[] = {"../sampleGraphs/pos.txt","../sampleGraphs/pos5.txt","../sampleGraphs/pos6.txt","../sampleGraphs/pos7.txt","../sampleGraphs/pos8.txt","../sampleGraphs/pos9.txt","../sampleGraphs/pos10.txt","../sampleGraphs/pos11.txt","../sampleGraphs/pos12.txt" };

    for(int j = 0; j < 9; j++) {
        Algorithm * d = new TSP();

        std::cout << "File: " << filePaths[j] << std::endl;
        d->load(filePaths[j]);
        for (int i = Algorithm::BRUTETSP; i != Algorithm::LAST; i++) {
            d->select(i);
            d->execute();
            d->printSolution();
        }
        delete d;
    }




    return 0;
}