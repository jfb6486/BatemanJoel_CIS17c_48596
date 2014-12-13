//
//  DoublyLinkedList.h
//  LinkedList
//
//  Created by Joel Bateman on 11/13/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

#ifndef __LinkedList__DoublyLinkedList__
#define __LinkedList__DoublyLinkedList__

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class DoublyLinkedList{
private:
    struct Node{
        Node *next;
        Node *prev;
        int data;
    };

    Node *head; //The first item of the list
    Node *tail; //The last item of the list
    int size; //Zero based count of the items within the list
        
public:
    //Default constructor
    DoublyLinkedList();
    
    //Copy constructor
    DoublyLinkedList(const DoublyLinkedList&);
    
    //Deconstructor
    ~DoublyLinkedList();
    
    //Functions
    int getSize();
    void insertNode(int);
    void deleteNode(int);
    void printList();
    void clear();
    Node getAt(int);
};
#endif /* defined(__LinkedList__DoublyLinkedList__) */
