//
// Created by Reid Russell on 9/24/19.
//

#include "Search.h"

Search::Search()
{
    fileNames.push_back("../SampleGraph/graph.txt");
    fileNames.push_back("../SampleGraph/weights.txt");
    fileNames.push_back("../SampleGraph/positions.txt");

}


void Search::load(string filePath)
{

    //::::::::::::::::Read in graph and build graphs
    if(filePath == "../SampleGraph/graph.txt") {
        //::::::::::::::::::::::::::::::::::::::: Build graph (Adjacency List)
        vector<vector<int> > children; // used for assigning pointers to paths after nodes are read in
        int counter = 0;
        ifstream file;
        file.open(filePath);
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
                // TODO : Clean this up because now there is no reason to check everytime we get the connections only
                //  when getting the first element (dont even need to check)
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
            vector<float> temp(nodes.size());
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
        ifstream file;
        file.open(filePath);
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
                float weight = stoi(item);




                //Assign weight for matrix (do -1 for indexing purposes)
                adjMatrix[source-1][destination-1] = weight;

                int index = graph.findIndex(source);
                for(int i = 0; i < graph.getInnerSize(index);  i++)
                {
                    if(graph.getAt(index,i)->getSrc() == source && graph.getAt(index,i)->getDest() == destination)
                    {
                        graph.getAt(index,i)->setWeight(weight);
                        break;
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
        file.open(filePath);
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
    string file = "";
    for(int i = 0; i < fileNames.size();i++) {
        file = fileNames[i];
        load(file);
    }
    //time.clear();
    // TODO : DO THIS LATER

    vector<vector<float> >* mPointer = &adjMatrix;

    BFS bfs(start, end);
    DFS dfs(start, end);

    vector<Path> p;
    vector<Path> pM;
    vector<Path> dfsP;
    vector<Path> dfsPM;

        switch (searchAlgo) {

            case 0:
                //cout << "Bubble" << endl;

                //time.push_back(.execute(data));
                p= bfs.BFSAdjList(&graph, nodes.size());
                //log();

                pM = bfs.BFSMatrix(mPointer, nodes.size());
                break;

            case 1:

                dfsP = dfs.DFSAdjList(&graph, nodes.size());
                dfsPM = dfs.DFSMatrix(mPointer, nodes.size());
                break;


        }
        cout << "BFS : " << endl;
        cout << "AdjacencyList:" << endl;
    for(int i = 0; i< p.size(); i++)
    {
        cout << "Hop: " << i << endl;
        p[i].printPath();
    }
    cout << endl;
    cout << "Matrix" << endl;
    for(int i = 0; i< pM.size(); i++)
    {
        cout << "Hop: " << i << endl;
        pM[i].printPathMat();
    }
    cout << "DFS : " << endl;
    cout << "AdjacencyList:" << endl;
    for(int i = 0; i< dfsP.size(); i++)
    {
        cout << "Hop: " << i << endl;
        dfsP[i].printPath();
    }
    cout << "Matrix:" << endl;
    for(int i = 0; i< dfsPM.size(); i++)
    {
        cout << "Hop: " << i << endl;
        dfsPM[i].printPathMat();
    }




//    //cout << "executing" << endl;
//    Bubble b;
//    Insertion ins;
//    Merge m;
//    string file = "";
//    for(int i = 0; i < fileNames.size();i++)
//    {
//        file = fileNames[i];
//        switch (sortAlgo) {
//
//            case 0:
//                //cout << "Bubble" << endl;
//                load(file);
//                time.push_back(b.execute(data));
//                log();
//                break;
//            case 1:
//                //cout << "insertion"<<endl;
//                load(file);
//                time.push_back(ins.execute(data));
//                log();
//                break;
//            case 2:
//                //cout << "merge"<<endl;
//                load(file);
//                time.push_back(m.execute(data));
//                log();
//                break;
//            case 3:
//                break;
//            default:;
//        }
//    }

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
    searchAlgo = n;
}


void Search::configure()
{

}


void Search::stats()
{
    if(searchAlgo == 0)
    {
        cout << "BFS Iterative:" << endl;
        for(int i = 0; i < time.size(); i++)
        {
            cout << fileNames[i] << ": "<< time[i].count() << endl;
        }
    }
//    else if(sortAlgo == 1)
//    {
//        cout << "BFS Recursive:" << endl;
//        for(int i = 0; i < time.size(); i++)
//        {
//            cout << fileNames[i] << ": "<< time[i].count() << endl;
//        }
//    }
//    else if(sortAlgo == 2)
//    {
//        cout << "DFS Iterative:" << endl;
//        for(int i = 0; i < time.size(); i++)
//        {
//            cout << fileNames[i] << ": "<< time[i].count() << endl;
//        }
//    }
}


void Search::log()
{

}