//
//  LinkedList.h
//  LinkedList
//
//  Created by Joel Bateman on 11/12/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

#ifndef LinkedList_LinkedList_h
#define LinkedList_LinkedList_h

#include <string>
#include <iostream>

using namespace std;

template<class T>
class Node
{
public:
    template<class U>
    friend class LinkedList;
    
private:
    T data;
    Node *next;
};

template<class T>
class LinkedList{
private:
    int size=0;
    Node<T>* head;
    
public:
    LinkedList(){
        head=NULL;
        size=0;
    }
    
    LinkedList(const LinkedList&);
    
    void prepend(Node<T>*, T);
    void append(T);
    string toString();
    virtual ~LinkedList();
    void getFirst();
    void getLast();
    void extractData(T);
    bool insertBefore(T, T);
    bool insertAfter(T, T);
    Node<T>* getPrevious(Node<T>*);
    void setBefore(Node<T>*, Node<T>*);
    LinkedList<T>& operator=(const LinkedList<T>&);
    Node<T>* getHead();
    
};
#endif
