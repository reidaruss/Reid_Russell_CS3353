//
// Created by Reid Russell on 9/24/19.
//

#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
class ListNode
{
    template<class U> friend class LinkedList;  //LISTNODE
private:
//TODO : Make a vector for children that holds node pointers to each child node.
//TODO : Add new addConnection() method to add a connection to a child
//TODO : Remove old next and prev pointers
    ListNode<T>* next;
    ListNode<T>* prev;
    //vector<ListNode<T>*> children;
    T payload;
    vector<int> position;

public:
    ListNode(T val);

    T getPayload(){return payload;}
    void setPosition(int x, int y, int z) {position.push_back(x); position.push_back(y); position.push_back(z);}
    vector<int> getPos(){ return position;}

};



template<class T>
class LinkedList        //LINKEDLIST
{
private:
    ListNode<T>* head, *tail;
    int length;
    ListNode<T>* curr;

public:
    LinkedList();
    T& operator[](int i);
    LinkedList& operator=(const LinkedList<T>& rhs);
    void insert(T val);
    void insertAt(int pos, T val);
    void removeAt(int pos);

    //void addChild();

    void removeFront();
    void removeBack();
    void addBack(T val);
    void addFront(T val);
    void resetIterator();
    int getLen();
    bool contains(T val);
    T getNext();    //return type was LinkedList<T>
    void clear();
    bool isEmpty();
    bool nextExists();
    string getCurr();
     //~LinkedList();




};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
    curr = nullptr;
}

template <typename T>
int LinkedList<T>::getLen()
{
    return length;
}


template <typename T>
ListNode<T>::ListNode(T val):next(nullptr),prev(nullptr),payload(val){}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    if(head != nullptr)
        this->clear();
    ListNode<T>* curr = rhs.head;
    while(curr != nullptr)
    {
        addBack(curr->payload);
        curr = curr->next;
    }
}



template <typename T>
T& LinkedList<T>::operator[](int i)
{
    ListNode<T>* temp = head;
    if(i >= length)
        cerr << "op[] Unable to access. Out of scope" << endl;
    else if(i == 0)
    {
        temp = head;
        return temp->payload;
    }
    else
    {

        if(head == nullptr)
        {
            return head->payload;
        }

        for(int j = 0; j < i; j++)
            temp = temp->next;
        return temp->payload;
    }
}



template <typename T>
void LinkedList<T>::insert(T val)
{
    if(head == nullptr)
    {
        head = new ListNode<T>(val);    //check if head is null and insert
        tail = head;
        length++;
    }
    else
    {
        tail->next = new ListNode<T>(val);
        tail->next->prev = tail;
        tail = tail->next;
        length++;
    }
}
template <typename T>
void LinkedList<T>::addFront(T val)
{
    if(head == nullptr)
    {
        head = new ListNode<T>(val);    //new node in front
        tail = head;
        length++;
    }
    else
    {
        curr = head;
        head = new ListNode<T>(val);
        head->next = curr;
        curr->prev = head;
        length++;
    }


}

template <typename T>
void LinkedList<T>::addBack(T val)
{
    if(tail == nullptr)
    {
        head = new ListNode<T>(val);
        tail = head;
        length++;
    }
    else
    {
        curr = tail;
        tail = new ListNode<T>(val);
        tail->prev = curr;
        curr->next = tail;
        length++;
    }
}

template <typename T>
void LinkedList<T>::insertAt(int pos, T val)
{
    ListNode<T>* curr = head;
    if(curr == nullptr)
    {
        addFront(val);
        return;
    }
    while(curr->next != nullptr && pos-1 > 0)
    {
        curr = curr->next;
        pos--;
    }
    if(curr == head)
        addFront(val);
    else if(curr == tail)
        addBack(val);
    else
    {
        ListNode<T>* temp = new ListNode<T>(val);
        temp->prev = curr;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        length++;
    }
}

template <typename T>
void LinkedList<T>::removeAt(int pos)
{
    if(pos >=length)
        throw "Out of range.";
    ListNode<T>* curr = head;
    while(pos > 0)
    {
        curr = curr->next;
        pos--;
    }
    if(curr == head)
        removeFront();
    else if(curr == tail)
        removeBack();
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        length--;

    }
}

template <typename T>
void LinkedList<T>::removeFront()
{
    if(head == nullptr)
        return;
    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        length--;
    }
}
template <typename T>
void LinkedList<T>::removeBack()
{
    if(tail == nullptr)
        return;
    if(head == tail)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        length--;

    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        length--;
    }
}

template <typename T>
void LinkedList<T>::clear()
{
    while(length != 0)
        removeBack();
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    if(head == nullptr && tail == nullptr)
        return true;
    else
        return false;
}



template <typename T>
bool LinkedList<T>::contains(T val)
{
    curr = head;
    for(int i = 0; i< length ; i++)
    {
        if(curr->payload == val)
            return true;
        curr = curr->next;
    }
    return false;
}



template <typename T>
void LinkedList<T>::resetIterator()
{
    curr = head;

}

template <typename T>
T LinkedList<T>::getNext()  //return type was LinkedList<T>
{
    if(nextExists()) {
        curr = curr->next;
        return curr->payload;
    }

}

template <typename T>
bool LinkedList<T>::nextExists()    //check if curr->next exists
{
    if(curr->next == nullptr)
        return false;
    else
        return true;
}

template <typename T>
string LinkedList<T>::getCurr()
{
    return curr->payload;
}

//template <typename T>
//LinkedList<T>::~LinkedList()        //destructor
//{
//    if(this->head != nullptr)
//    {
//        ListNode<T>* temp = this->head;
//        while(temp->next!= nullptr)
//        {
//            temp = temp->next;
//            delete temp->prev;
//        }
//        delete temp;
//    }
//
//
//}


#endif //LAB2_LINKEDLIST_H
