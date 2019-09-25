//
// Created by Reid Russell on 9/24/19.
//

#ifndef LAB2_SEARCH_H
#define LAB2_SEARCH_H

#include "algorithm.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

class Search :public Algorithm{
private:
    int searchAlgo;


public:
    Search();

    void load(string filePath);
    void execute();
    void display();
    void save();
    void select(int n);
    void configure();
    void stats();
    void log();
};


#endif //LAB2_SEARCH_H
