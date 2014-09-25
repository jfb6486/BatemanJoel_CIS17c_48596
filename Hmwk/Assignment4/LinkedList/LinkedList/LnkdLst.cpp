//
//  LnkdLst.cpp
//  LinkedList
//
//  Created by Joel Bateman on 9/24/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <sstream>
#include "LnkdLst.h"
#include <iostream>

void LnkdLst::append(int n){
    Node *newNode;  // To point to a new Node
    Node *nodePtr;  // To move through the list
    
    // Allocate a new Node and store data there
    newNode = new Node;
    newNode->data=n;
    newNode->next=NULL;
    size++; // Increase list size by 1
    
    // Make newNode the first node
    if(!head){
        head=newNode;
    }
    else{
        // Initialize nodePtr to head of list
        nodePtr=head;
        
        // Find the last nodePtr in the list
        while (nodePtr->next) {
            nodePtr=nodePtr->next;
        }
        
        // Insert newNode as the last node
        nodePtr->next=newNode;
    }
}

string LnkdLst::toString(){
    Node *nodePtr;
    stringstream ss; // reads from nodePtr->data
    string printNode; // save data from ss
    
    // Position nodePtr at the head of the list
    nodePtr=head;
    
    // While nodePtr points to a node, transverse the list
    for (Node*nodePtr=head;nodePtr!=NULL;nodePtr=nodePtr->next){
        ss<<nodePtr->data<<" ";
    }
    printNode=ss.str();
    cout<<"Size: "<<size<<" \n";
    return printNode;
}

LnkdLst::~LnkdLst(){
    Node *nodePtr;
    Node *nextNode;
    
    // Position the nodePtr at the head of the list
    nodePtr=head;
    
    // While nodePtr is not at the end of list
    while (nodePtr!=NULL){
        
        // Save a pointer to the next node
        nextNode=nodePtr->next;
        
        // Delete the current Node
        delete nodePtr;
        
        // Position nodePtr at next node
        nodePtr=nextNode;
    }
}
