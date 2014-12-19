//
//  LnkdLst.h
//  LnkdLst
//
//  Created by Joel Bateman on 09/24/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __LnkdLst__LnkdLst__
#define __LnkdLst__LnkdLst__

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList &o);
    ~LinkedList();
    
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
    class Node{
    public:
        T data;
        Node *next;
        Node(){
            data = NULL;
            next = NULL;
        }
        Node(T dataPortion, Node *nextNode = 0){
            data = dataPortion;
            next = nextNode;
        }
    };
    Node *head;
    Node *tail;
};
#endif /* defined(__LnkdLst__LnkdLst__) */
