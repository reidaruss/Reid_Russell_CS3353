//
// Created by Reid Russell on 9/24/19.
//

#include "Search.h"

Search::Search()
{

}


void Search::load(string filePath)
{
    if(filePath == "../SampleGraph/graph.txt") {
        vector<vector<int> > children;
        int counter = 0;
        ifstream file;
        file.open("../SampleGraph/graph.txt");
        string line;
        string item;
        if (file.is_open()) {
            while (!file.eof()) {
                vector<int> child;
                getline(file, line, '\n');
                istringstream iss(line);
                string s = "";
                getline(iss, item, ',');
                ListNode<int> node(stoi(item));
                if(nodes.size() == 0)
                {
                    nodes.push_back(node);
                }
                for (int i = 0; i < nodes.size(); i++) {
                    if (nodes[i].getPayload() == stoi(item))
                    {
                        break;
                    }
                    else if(i == nodes.size()-1)
                    {
                        nodes.push_back(node);
                        break;
                    }
                }

                ListNode<int> * src = &node;
                while (getline(iss, item, ',')) {
                    for (int i = 0; i < nodes.size(); i++) {
                        if(nodes[i].getPayload() == stoi(item)) {
                            break;
                        }
                        else if(i == nodes.size()-1)
                        {
                            ListNode<int> tempNode(stoi(item));
                            nodes.push_back(tempNode);
                            break;
                        }

                    }

                    child.push_back(stoi(item));

                }
                children.push_back(child);
                child.clear();

            }
        }
        ListNode<int> * src = nullptr;
        ListNode<int> * dest = nullptr;
        for(int i = 0; i < children.size(); i++)
        {
            for(int j = 0; j < children[i].size(); j++)
            {

                int findSrc = i + 1;
                int findDest = children[i][j];
                for(int k = 0; k < nodes.size(); k++) {
                    if (nodes[k].getPayload() == findSrc) {
                        src = &nodes[k];
                        break;
                    }
                }
                for(int k = 0; k < nodes.size(); k++)
                {
                    if(nodes[k].getPayload() == findDest)
                    {
                        dest = &nodes[k];
                    }
                }
                Path p(src, dest);
                graph.add(i, p);
            }
        }
        file.close();
    }

    if(filePath == "../SampleGraph/weights.txt")
    {
        // TODO : Read in the weights into subpath objects
        ifstream file;
        file.open("../SampleGraph/weights.txt");
        string line;
        string item;
        if (file.is_open())
        {
            while (!file.eof())
            {
                getline(file, line, '\n');
                istringstream iss(line);
                getline(iss, item, ',');
                int source = stoi(item);
                getline(iss, item, ',');
                int destination = stoi(item);
                getline(iss, item, ',');
                int weight = stoi(item);

                for(int i = 0; i < graph.getSize(); i++)
                {
                    for(int j = 0; j < graph.getInnerSize(i); j++)
                    {
                        if(graph.getAt(i,j)->getSrc() == source && graph.getAt(i,j)->getDest() == destination)
                        {
                            graph.getAt(i,j)->setWeight(weight);
                            break;
                        }
                    }
                }
            }

        }
        file.close();



    }

    if(filePath == "../SampleGraph/positions.txt")
    {
        ifstream file;
        file.open("../SampleGraph/positions.txt");
        string line;
        string item;
        if (file.is_open())
        {
            while (!file.eof())
            {
                getline(file, line, '\n');
                istringstream iss(line);
                getline(iss, item, ',');
                int find = stoi(item);
                getline(iss, item, ',');
                int x = stoi(item);
                getline(iss, item, ',');
                int y = stoi(item);
                getline(iss, item, ',');
                int z = stoi(item);

                for(int i = 0; i < nodes.size(); i++)
                {
                    if(nodes[i].getPayload() == find)
                    {
                        nodes[i].setPosition(x,y,z);
                    }
                }


            }

        }
        file.close();

    }





}


void Search::execute()
{

}
void Search::display()
{

    for(int i = 0; i < graph.getSize(); i ++)
    {
        for(int j = 0; j < graph.getInnerSize(i); j ++)
        {
            cout << graph.getAt(i, j)->getSrc() << "-->"<< graph.getAt(i,j)->getDest() << endl;
            cout << "Weight: " << graph.getAt(i, j)->getWeight() << endl;
        }
        cout << endl << endl;
    }

    for(int i = 0; i < nodes.size(); i++)
    {
        cout << "Node: "<< nodes[i].getPayload() << endl;
        cout << "Position: " << nodes[i].getPos()[0] << "," << nodes[i].getPos()[1] << "," << nodes[i].getPos()[2] << endl << endl;
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