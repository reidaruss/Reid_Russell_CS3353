//
// Created by Reid Russell on 9/24/19.
//

#include "Search.h"

Search::Search()
{

}


void Search::load(string filePath)
{

    //::::::::::::::::Read in graph and build graphs
    if(filePath == "../SampleGraph/graph.txt") {
        //::::::::::::::::::::::::::::::::::::::: Build graph (Adjacency List)
        vector<vector<int> > children; // used for assigning pointers to paths after nodes are read in
        int counter = 0;
        ifstream file;
        file.open("../SampleGraph/graph.txt");
        string line;
        string item;
        if (file.is_open()) {
            while (!file.eof()) {
                vector<int> child;
                getline(file, line, '\n');  //Get first line
                istringstream iss(line);
                string s = "";
                getline(iss, item, ',');    //Get First element (src node)
                ListNode<int> node(stoi(item));
                if(nodes.size() == 0)
                {
                    nodes.push_back(node);
                }
                // TODO : Clean this up because now there is no reason to check everytime we get the connections only when getting the first element (dont even need to check)
                for (int i = 0; i < nodes.size(); i++) {    //make sure starting node not in nodes vector already
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
                while (getline(iss, item, ',')) {   //Get all the children, put into children vector
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


        ListNode<int> * src = nullptr;  //Loop through nodes vector and assign pointers to children so that path can be built
        ListNode<int> * dest = nullptr;
        for(int i = 0; i < children.size(); i++)
        {
            for(int j = 0; j < children[i].size(); j++)
            {

                int findSrc = i + 1;
                int findDest = children[i][j];  //These are the two path elements we are looking for
                for(int k = 0; k < nodes.size(); k++) { //Find source
                    if (nodes[k].getPayload() == findSrc) {
                        src = &nodes[k];
                        break;
                    }
                }
                for(int k = 0; k < nodes.size(); k++)   //Find destination
                {
                    if(nodes[k].getPayload() == findDest)
                    {
                        dest = &nodes[k];
                    }
                }
                Path p;
                p.setPath(src, dest);  //Create path and add to adjacency list in the correct index
                graph.add(i, p);
            }
        }
        file.close();


        //::::::::::::::::::::::::::::::::: Matrix
        //Create the nxn matrix- creating it here because now program has number of nodes
        for(int i = 0; i < nodes.size(); i++)
        {
            vector<int> temp(nodes.size());
            adjMatrix.push_back(temp);
        }

        //Initially fill matrix with zeros
        for(int i = 0; i < adjMatrix.size(); i++)
        {
            for(int j = 0; j < adjMatrix[i].size(); j++)
            {
                adjMatrix[i][j] = 0;
            }

        }
    }



// :::::::::::::::::::Read in weights and populate graphs
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
                getline(file, line, '\n');  //Get source, destination and weight
                istringstream iss(line);
                getline(iss, item, ',');
                int source = stoi(item);
                getline(iss, item, ',');
                int destination = stoi(item);
                getline(iss, item, ',');
                int weight = stoi(item);




                //Assign weight for matrix (do -1 for indexing purposes)
                adjMatrix[source-1][destination-1] = weight;

                //Find each path associated with a weight and assign.
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

    //:::::::::::::::::::Assign node positions
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
                getline(file, line, '\n');  //get the node to assign position to
                istringstream iss(line);
                getline(iss, item, ',');
                int find = stoi(item);
                getline(iss, item, ',');
                int x = stoi(item);
                getline(iss, item, ',');
                int y = stoi(item);
                getline(iss, item, ',');
                int z = stoi(item);

                for(int i = 0; i < nodes.size(); i++)   //assign position
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


void Search::execute(int start, int end)
{
    BFS bfs(start, end);
    vector<Path> p= bfs.BFSAdjList(&graph, nodes.size());
    for(int i = 0; i< p.size(); i++)
    {
        cout << "Hop: " << i << endl;
        p[i].printPath();
    }

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

    for(int i = 0; i < adjMatrix.size(); i++)
    {
        for(int j = 0; j < adjMatrix[i].size(); j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
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