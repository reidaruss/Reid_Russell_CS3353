#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>
using namespace std;

class Algorithm{
public:
    virtual void load(string filename) = 0;
    virtual void execute() = 0;
    virtual void display() = 0;
    virtual void select() = 0;
    virtual void save() = 0;
    virtual void configure() = 0;


};




#endif // ALGORITHM_H
