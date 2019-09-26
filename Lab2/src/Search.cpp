//
// Created by Reid Russell on 9/24/19.
//

#include "Search.h"

Search::Search()
{
    graph = new LinkedList<int>();
}


//TODO : Add file input and generation of graph
void Search::load(string filePath)
{
    vector<int> children;
    ifstream file;
    file.open("../SampleGraph/graph.txt");
    string line;
    string item;
    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file,line,'\n');
            istringstream iss(line);
            string s = "";
            getline(iss,item,',');
            children.push_back(stoi(item));
            while(getline(iss,item, ','))
            {
                s += item;

            }
            children.push_back(stoi(s));
        }
    }
    for(int i = 0; i < children.size(); i++)
    {
        cout << children[i] << endl;
    }
// TODO : Create a method in Linked List addConnection that checks if a child node exists, and if not creates a new node
//         and adds a connection.
//    graph->addBack(10);
//    graph->addBack(20);
//    graph->addBack(30);
}


void Search::execute()
{

}
void Search::display()
{
    for(int i = 0; i < graph->getLen(); i++)
    {
        cout << (*graph)[i] << endl;

    }
}


void Search::save()
{

}


void Search::select(int n)
{

}


void Search::configure()
{

}


void Search::stats()
{

}


void Search::log()
{

}