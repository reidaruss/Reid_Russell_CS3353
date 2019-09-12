#include "sort.h"

//Stores fileNames into vector to be looped through for loading datasets.
Sort::Sort()
{
    fileNames.push_back("../lab1/src/data/unsorted/ten_random.txt");
    fileNames.push_back("../lab1/src/data/unsorted/ten_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/ten_partUni.txt");
    fileNames.push_back("../lab1/src/data/unsorted/ten_partRand.txt");
    fileNames.push_back("../lab1/src/data/unsorted/thousand_random.txt");
    fileNames.push_back("../lab1/src/data/unsorted/thousand_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/thousand_partUni.txt");
    fileNames.push_back("../lab1/src/data/unsorted/thousand_partRand.txt");
    fileNames.push_back("../lab1/src/data/unsorted/tenThousand_random.txt");
    fileNames.push_back("../lab1/src/data/unsorted/tenThousand_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/tenThousand_partUni.txt");
    fileNames.push_back("../lab1/src/data/unsorted/tenThousand_partRand.txt");
    fileNames.push_back("../lab1/src/data/unsorted/hundThousand_random.txt");
    fileNames.push_back("../lab1/src/data/unsorted/hundThousand_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/hundThousand_partUni.txt");
    fileNames.push_back("../lab1/src/data/unsorted/hundThousand_partRand.txt");
}

//loads individual datasets into data
void Sort::load(string filePath)
{
    //cout << "loading: "<< filePath <<endl;
    data.clear();
    ifstream infile;
    int size;
    infile.open(filePath);
    infile >> size;

    for(int i=0; i< size; i++)
    {
        int num;
        infile >> num;
        data.push_back(num);
    }
    infile.close();
}

//Takes in enum case from main, executes each algorithm on every dataset
//and records timing for stats.
void Sort::execute()
{
    time.clear();
    //cout << "executing" << endl;
    Bubble b;
    Insertion ins;
    Merge m;
    string file = "";
    for(int i = 0; i < fileNames.size();i++)
    {
        file = fileNames[i];
        switch (sortAlgo) {

        case 0:
            //cout << "Bubble" << endl;
            load(file);
            time.push_back(b.execute(data));
            log();
            break;
        case 1:
            //cout << "insertion"<<endl;
            load(file);
            time.push_back(ins.execute(data));
            log();
            break;
        case 2:
            //cout << "merge"<<endl;
            load(file);
            time.push_back(m.execute(data));
            log();
            break;
        case 3:
            break;
        default:;
        }
    }
}

//Prints the whole sorted solution.
void Sort::display()
{
    for(int i = 0; i < big_data.size();i++)
    {
        cout << big_data[i] << endl;
    }

}

//takes in enum from main and sets algorithm type variable
void Sort::select(int n)
{
    sortAlgo = n;
}

//adds newly sorted datasets to the large dataset that is used in
//display() and save()
void Sort::log()
{
    for(int i = 0; i < data.size();i++)
    {
        big_data.push_back(data[i]);
    }
}

//Saves the large vector will sorted solution to file.
void Sort::save()
{

    ofstream fileout;
    fileout.open("../lab1/src/data/sorted/output.txt");

    for(int i = 0; i < big_data.size(); i++)
    {
        fileout << big_data[i] << endl;
    }
    fileout.close();

}

//Prints out stats for each Sorting algorithm and every dataset
//for each whith the associated dataset filename.
void Sort::stats()
{
    if(sortAlgo == 0)
    {
        cout << "Bubble:" << endl;
        for(int i = 0; i < time.size(); i++)
        {
            cout << fileNames[i] << ": "<< time[i].count() << endl;
        }
    }
    else if(sortAlgo == 1)
    {
        cout << "Insertion:" << endl;
        for(int i = 0; i < time.size(); i++)
        {
            cout << fileNames[i] << ": "<< time[i].count() << endl;
        }
    }
    else if(sortAlgo == 2)
    {
        cout << "Merge:" << endl;
        for(int i = 0; i < time.size(); i++)
        {
            cout << fileNames[i] << ": "<< time[i].count() << endl;
        }
    }
}

//For future use.
void Sort::configure()
{

}

