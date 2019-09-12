#include "sort.h"

Sort::Sort()
{
    fileNames.push_back("../lab1/src/data/unsorted/ten_random.txt");
    fileNames.push_back("../lab1/src/data/unsorted/ten_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/ten_partUni.txt");
    fileNames.push_back("../lab1/src/data/unsorted/ten_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/thousand_random.txt");
    fileNames.push_back("../lab1/src/data/unsorted/thousand_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/thousand_partUni.txt");
    fileNames.push_back("../lab1/src/data/unsorted/thousand_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/tenThousand_random.txt");
    fileNames.push_back("../lab1/src/data/unsorted/tenThousand_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/tenThousand_partUni.txt");
    fileNames.push_back("../lab1/src/data/unsorted/tenThousand_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/hundThousand_random.txt");
    fileNames.push_back("../lab1/src/data/unsorted/hundThousand_reverse.txt");
    fileNames.push_back("../lab1/src/data/unsorted/hundThousand_partUni.txt");
    fileNames.push_back("../lab1/src/data/unsorted/hundThousand_reverse.txt");
}

void Sort::load(string filePath)
{
    cout << "loading: "<< filePath <<endl;
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

}

void Sort::execute()
{
    cout << "executing" << endl;
    Bubble b;
    Insertion ins;
    Merge m;
    string file = "";
    for(int i = 0; i < fileNames.size();i++)
    {
        file = fileNames[i];
        switch (sortAlgo) {

        case 0:
            cout << "Bubble" << endl;
            load(file);
            b.execute(data);
            break;
        case 1:
            cout << "insertion"<<endl;
            load(file);
            ins.execute(data);
            break;
        case 2:
            cout << "merge"<<endl;
            load(file);
            m.execute(data);
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

}

void Sort::configure()
{

}

