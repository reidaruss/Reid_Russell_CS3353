
#include "Algorithm.h"
#include "TSP.h"

int main() {
    std::srand(std::time(0));




    //Please place test graphs in sampleGraphs and modify filePaths with the desired graphs and the number of files.
    std::string filePaths[] = {"4.txt","5.txt","6.txt","7.txt","8.txt","9.txt","10.txt","11.txt","12.txt","13.txt","14.txt","15.txt","16.txt","17.txt","18.txt" ,"19.txt","20.txt","21.txt"};

    int numFiles = 18;
    for(int j = 0; j < numFiles; j++) {
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