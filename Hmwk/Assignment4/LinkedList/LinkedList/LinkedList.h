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

template <class T>
class LinkedList
{
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    LinkedList(const LinkedList &l){
        for (Node *ptr=l.head;ptr!=NULL;ptr=ptr->next){
            addToTail(ptr->data);
        }
    }
    ~LinkedList(){
        Node *p;
        
        while (!isEmpty())
        {
            p = head->next;
            delete head;
            head = p;
        }
    }
    
    void insertBefore(T reference, T data);
    void insertAfter(T reference, T data);
    void prepend(T data);
    void append(T data);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(T data);
    bool contains(T data);
    T peekFirst();
    T peekLast();
    bool isEmpty();
    void toString();
    
private:
    class Node
    {
    public:
        T data;
        Node *next;
        
        Node(){
            data = NULL;
            next = NULL;
        }
        
        Node(T dataPortion, Node *nextNode=0){
            data = dataPortion;
            next = nextNode;
        }
    };
    
    Node *head;
    Node *tail;
};

#endif
