#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>
using namespace std;

class Algorithm{
public:
    virtual void load(string filePath) = 0;
    virtual void execute(int start, int end) = 0;
    virtual void display() = 0;
    virtual void select(int n) = 0;
    virtual void save() = 0;
    virtual void stats() = 0;
    virtual void configure() = 0;

    enum algos{BUBBLE=0,INSERTION,MERGE,LAST};

};




#endif // ALGORITHM_H
