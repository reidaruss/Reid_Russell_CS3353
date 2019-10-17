//
// Created by Reid Russell on 10/14/19.
//

#ifndef LAB2_ADJACENCYLIST_H
#define LAB2_ADJACENCYLIST_H

#include "LinkedList.h"
#include "Path.h"

template<class T>
class AdjacencyList
{
private:
    LinkedList<LinkedList<T>> data;
    int size;
public:

    AdjacencyList();
    void add(int index, T val);
    void insert(T find, T val);
    LinkedList<T> findWhereFirstIs(string val); //find the linked list associated with a string
    T stepIterator(string val);
    T* getAt(int i, int j);
    int getSize();
    void resetIters();
    int getInnerSize(int i);
    int findIndex(int src);
    string getIter(string val); //get curr
};



template <typename T>
AdjacencyList<T>::AdjacencyList()
{
    size = 0;
}

template <typename T>
void AdjacencyList<T>::add(int index, T val)
{
    if(size <= index)
    {
        LinkedList<T> list;
        data.addBack(list);
        data[index].addBack(val);
        size++;
    }
    else
    {
        data[index].addBack(val);
    }

}

template <typename T>
void AdjacencyList<T>::insert(T find, T val)
{
    bool added1 = false;    //bool to check if find has been added
    bool added2 = false;    //bool to check if val has been added
    for(int i = 0; i < size; i ++)
    {
        if(data[i][0] == find)
        {
            data[i].addBack(val);   //add back val if find is already there.
            added1 = true;
            break;
        }
    }

    if(added1 == false) //if find has not been found create a new link list push both vals then push to adj list
    {
        LinkedList<T> temp;
        temp.addBack(find);
        temp.addBack(val);
        data.addBack(temp);
        size++;
    }



}
template <typename T>
T* AdjacencyList<T>::getAt(int i, int j)    //get element at (used in tests)
{
    return &data[i][j];
}


template <typename T>
LinkedList<T> AdjacencyList<T>::findWhereFirstIs(string val)    //find where string is and return that linked list
{
    for(int i =0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
            return data[i];
    }
}

template <typename T>
int AdjacencyList<T>::getSize()
{
    return size;
}


template <typename T>
void AdjacencyList<T>::resetIters() //reset all curr to head;
{
    for(int i = 0; i < size; i ++)
    {
        data[i].resetIterator();
    }
}

template <typename T>
string AdjacencyList<T>::getIter(string val)    //get curr
{
    for(int i = 0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
            return data[i].getCurr();
    }


}


template <typename T>
T AdjacencyList<T>::stepIterator(string val)
{
    for(int i =0; i < data.getLen(); i++)
    {
        if(data[i][0] == val)
        {
            return data[i].getNext();//sets curr = curr->next and returns curr->payload.
        }
    }

}

template <typename T>
int AdjacencyList<T>::findIndex(int src)
{
    for(int i = 0; i < size; i++)
    {
        if(data[i][0].getSrc() == src)
            return i;
    }
}

template <typename T>
int AdjacencyList<T>::getInnerSize(int i)   //get size of inner ll
{
    return data[i].getLen();
}



#endif //LAB2_ADJACENCYLIST_H
