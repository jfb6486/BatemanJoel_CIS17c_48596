//
//  SinglyLinkedList.h
//  LnkdLst
//
//  Created by Joel Bateman on 10/30/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __LnkdLst__SinglyLinkedList__
#define __LnkdLst__SinglyLinkedList__

#include <stdio.h>
#include <string>

template <class T>
class SinglyLinkedList
{
public:
    SinglyLinkedList(){head=tail=NULL;}
    ~SinglyLinkedList(){
        Node *p;
        while (!isEmpty()){
            p = head->next;
            delete head;
            head = p;
        }
    }
    
    bool isEmpty();
    T const peekFirst();
    T const peekLast();
    void prepend(T);
    void append(T);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(T);
    bool contains(T);
    
private:
    class Node{
    public:
        int data;
        Node *next;
        
        Node(){
            data=0;
            next=NULL;
        }
        Node(int dataPortion, Node *nextNode=0){
            data = dataPortion;
            next = nextNode;
        }
    };
    Node *head;
    Node *tail;
};

#endif /* defined(__LnkdLst__SinglyLinkedList__) */
