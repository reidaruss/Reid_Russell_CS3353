#include "sort.h"

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
            break;
        case 1:
            //cout << "insertion"<<endl;
            load(file);
            time.push_back(ins.execute(data));
            break;
        case 2:
            //cout << "merge"<<endl;
            load(file);
            time.push_back(m.execute(data));
            break;
        case 3:
            break;
        default:;
        }
    }
}

void Sort::display()
{
    cout << "displaying" << endl;
}

void Sort::select(int n)
{
    sortAlgo = n;
}

void Sort::save()
{

}

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

void Sort::configure()
{

}

