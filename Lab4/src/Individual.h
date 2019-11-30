//
// Created by Reid Russell on 11/23/2019.
//

#ifndef LAB4_INDIVIDUAL_H
#define LAB4_INDIVIDUAL_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

class Individual {
private:
    std::string GENES;
    std::string TARGET;
    std::string chromosome;
    int fitness;

public:
    Individual();
    Individual(std::string chromosome);
    bool operator < (Individual const & ind);
//    bool operator = (Individual const & ind);
    Individual mate(Individual parent2);
    int cal_fitness();
    float randNum(float start, float end);
    char mutatedGenes();
    std::string newGnome();
    void sortInds(std::vector<Individual>& pop);
    bool operator > (Individual const & ind);


    int getFitness(){return fitness;}
    std::string getChromosome(){return chromosome;}
};


#endif //LAB4_INDIVIDUAL_H
