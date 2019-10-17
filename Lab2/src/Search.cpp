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
    if(!loadedF)
    {
        string file = "";
        for (int i = 0; i < fileNames.size(); i++) {
            file = fileNames[i];
            load(file);
        }
        loadedF = true;
    }


    vector<vector<float> >* mPointer = &adjMatrix;

    BFS bfs(start, end);
    DFS dfs(start, end);

    vector<Path> p;
    vector<Path> pM;
    vector<Path> dfsP;
    vector<Path> dfsPM;

    chrono::high_resolution_clock::time_point t1;
    chrono::high_resolution_clock::time_point t2;
    chrono::high_resolution_clock::time_point t3;
    chrono::high_resolution_clock::time_point t4;


        switch (searchAlgo) {

            case 0:

                t1 = chrono::high_resolution_clock::now();
                p= bfs.BFSAdjList(&graph, nodes.size());
                t2 = chrono::high_resolution_clock::now();
                bfsPath = p;
                bfsTime = chrono::duration_cast<chrono::duration<double>>(t2-t1);

                t3 = chrono::high_resolution_clock::now();
                pM = bfs.BFSMatrix(mPointer, nodes.size());
                t4 = chrono::high_resolution_clock::now();
                bfsPathMat = pM;
                bfsTimeMat = chrono::duration_cast<chrono::duration<double>>(t4-t3);
                break;

            case 1:
                t1 = chrono::high_resolution_clock::now();
                dfsP = dfs.DFSAdjList(&graph, nodes.size());
                t2 = chrono::high_resolution_clock::now();
                dfsPath = dfsP;
                dfsTime = chrono::duration_cast<chrono::duration<double>>(t2-t1);

                t3 = chrono::high_resolution_clock::now();
                dfsPM = dfs.DFSMatrix(mPointer, nodes.size());
                t4 = chrono::high_resolution_clock::now();
                dfsPathMat = dfsPM;
                dfsTimeMat = chrono::duration_cast<chrono::duration<double>>(t3-t4);
                break;

            case 2:
                t1 = chrono::high_resolution_clock::now();
                dkstra = dfs.DFSAdjList(&graph, nodes.size());
                t2 = chrono::high_resolution_clock::now();
                dkstraTime = chrono::duration_cast<chrono::duration<double>>(t2-t1);

//                t3 = chrono::high_resolution_clock::now();
//                dfsPM = dfs.DFSMatrix(mPointer, nodes.size());
//                t4 = chrono::high_resolution_clock::now();
//                dfsPathMat = dfsPM;
//                dfsTimeMat = chrono::duration_cast<chrono::duration<double>>(t2-t1);
                break;


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
    searchAlgo = n;
}


void Search::configure()
{

}


void Search::stats()
{
    if(searchAlgo == 0)
    {
        float totalDist = 0;
        int numHops = 0;
        float cost = 0;
        cout << "BFS Iterative:" << endl;
        cout << "Adjacency List: " << endl;
        for(int i = 0; i < bfsPath.size(); i++)
        {
            bfsPath[i].printPath();
            cout <<" , ";
            numHops ++;
            cost += bfsPath[i].getWeight();
            bfsPath[i].setDistance();
            totalDist += bfsPath[i].getDistance();
        }
        cout << endl;
        cout << "Number of Hops : " << numHops << endl;
        cout << "Total Cost     : " << cost << endl;
        cout << "Total Distance : " << totalDist << endl;
        // TODO : Add Total nodes explored
        cout << "Execution Time : " << bfsTime.count() << endl;
        cout << endl;

        numHops = 0;
        cost = 0;
        totalDist = 0;

        cout << "Adjacency Matrix: " << endl;
        for(int i = 0; i < bfsPathMat.size(); i++)
        {
            bfsPathMat[i].printPathMat();
            cout << " , ";
            numHops ++;
            cost += bfsPathMat[i].getWeight();
//            bfsPathMat[i].setDistance();
//            totalDist += bfsPathMat[i].getDistance();
        }
        cout << endl;
        cout << "Number of Hops : " << numHops << endl;
        cout << "Total Cost     : " << cost << endl;
//        cout << "Total Distance : " << totalDist << endl;
        // TODO : Add Total nodes explored
        cout << "Execution Time : " << bfsTimeMat.count() << endl;


//        cout << "BFS Recursive:" << endl;
//        for(int i = 0; i < bfsPathMat.size(); i++)
//        {
//
//            cout << fileNames[i] << ": "<< time[i].count() << endl;
//        }



    }

    else if(searchAlgo == 1)
    {
        float totalDist = 0;
        int numHops = 0;
        float cost = 0;
        cout << "DFS Iterative:" << endl;
        cout << "Adjacency List: " << endl;
        for(int i = 0; i < dfsPath.size(); i++)
        {
            dfsPath[i].printPath();
            cout <<" , ";
            numHops ++;
            cost += dfsPath[i].getWeight();
            dfsPath[i].setDistance();
            totalDist += dfsPath[i].getDistance();
        }
        cout << endl;
        cout << "Number of Hops : " << numHops << endl;
        cout << "Total Cost     : " << cost << endl;
        cout << "Total Distance : " << totalDist << endl;
        // TODO : Add Total nodes explored
        cout << "Execution Time : " << dfsTime.count() << endl;
        cout << endl;

        numHops = 0;
        cost = 0;

        cout << "Adjacency Matrix: " << endl;
        for(int i = 0; i < dfsPathMat.size(); i++)
        {
            dfsPathMat[i].printPathMat();
            cout << " , ";
            numHops ++;
            cost += dfsPathMat[i].getWeight();
        }
        cout << endl;
        cout << "Number of Hops : " << numHops << endl;
        cout << "Total Cost     : " << cost << endl;
        // TODO : Add Total nodes explored
        cout << "Execution Time : " << dfsTimeMat.count() << endl;


//        cout << "DFS Recursive:" << endl;
//        for(int i = 0; i < bfsPathMat.size(); i++)
//        {
//
//            cout << fileNames[i] << ": "<< time[i].count() << endl;
//        }

    }

    else if(searchAlgo == 2)
    {
        float totalDist = 0;
        int numHops = 0;
        float cost = 0;
        cout << "Dijkstra :" << endl;
        cout << "Adjacency List: " << endl;
        for(int i = 0; i < dkstra.size(); i++)
        {
            dkstra[i].printPath();
            cout <<" , ";
            numHops ++;
            cost += dkstra[i].getWeight();
            dkstra[i].setDistance();
            totalDist += dkstra[i].getDistance();
        }
        cout << endl;
        cout << "Number of Hops : " << numHops << endl;
        cout << "Total Cost     : " << cost << endl;
        cout << "Total Distance : " << totalDist << endl;
        // TODO : Add Total nodes explored
        cout << "Execution Time : " << dkstraTime.count() << endl;
        cout << endl;


    }


}


void Search::log()
{

}