//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Joel Bateman on 11/12/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//


#include "LinkedList.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template<class T>
void LinkedList<T>::append(T n){
    Node<T>* newNode;  // To point to a new Node
    Node<T>* nodePtr;  // To move through the list
        
    // Allocate a new Node and store data there
    newNode = new Node<T>;
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

template<class T>
string LinkedList<T>::toString(){
    Node<T>* nodePtr;
    stringstream ss; // reads from nodePtr->data
    string printNode; // save data from ss
    int count=0;
    
    // Position nodePtr at the head of the list
    nodePtr=head;
    
    // While nodePtr points to a node, transverse the list
    for (Node<T>* nodePtr=head;nodePtr!=NULL;nodePtr=nodePtr->next){
        if(nodePtr->data!=0){
            count++;
            ss<<count<<")"<<nodePtr->data<<" \n";
        }
    }
    printNode=ss.str();
    cout<<"Size: "<<size<<" \n";
    
    return printNode;
}

template<class T>
LinkedList<T>::~LinkedList(){
    Node<T>* nodePtr;
    Node<T>* nextNode;
    
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

template<class T>
void LinkedList<T>::prepend(Node<T>* n, T data){
    
    // stl list name = push_front
    // Allocate a new Node and store the data there
    Node<T>* temp;
    temp=new Node<T>;
    temp->data=data;
    temp->next=head; // Point newly allocated Node at the head of the list
    head=temp;  // The newly allocated Node is the head of the list
    size++; // Increase the size of the list by 1
}

template<class T>
void LinkedList<T>::getFirst(){
    
    cout<<"First: ";
    cout<<head->data;
}

template<class T>
void LinkedList<T>::getLast(){
    
    cout<<"Last: ";
    for(Node<T>* nodePtr=head;nodePtr!=NULL;nodePtr=nodePtr->next){
        if(nodePtr->next==NULL){
            cout<<nodePtr->data;
        }
    }
}

template<class T>
void LinkedList<T>::extractData(T read){
    for(Node<T>* nodePtr=head;nodePtr!=NULL;nodePtr=nodePtr->next){
        if(nodePtr->data==read){
            cout<<nodePtr->data;
        }
    }
}

template<class T>
bool LinkedList<T>::insertBefore(T insertAtNode, T newValue){
    
    Node<T>* nodePtrPre=NULL;
    for(Node<T>* nodePtr=head ; nodePtr!=NULL; nodePtr=nodePtr->next)
    {
        if(nodePtr->data==insertAtNode)
        {
            Node<T>* newNode=new Node<T>;
            newNode->data=newValue;
            newNode->next=nodePtr;
            nodePtrPre->next=newNode;
            size++;
            
            return true;
        }
        nodePtrPre = nodePtr;
    }
    return false; //false
}

template<class T>
bool LinkedList<T>::insertAfter(T insertAtNode, T newValue){
    
    for(Node<T>* nodePtr=head ; nodePtr!=NULL; nodePtr=nodePtr->next)
    {
        if(nodePtr->data==insertAtNode)
        {
            Node<T>* newNode=new Node<T>;
            newNode=new Node<T>;
            newNode->data=newValue;
            newNode->next=nodePtr->next;
            nodePtr->next=newNode;
            size++;
            
            return true;
        }
    }
    return false;
}

template<class T>
Node<T>* LinkedList<T>::getPrevious(Node<T>* node){
    Node<T>* temp=head;
    Node<T>* previous=head;
    
    if(node==head){
        return NULL;
    }
    
    while(temp && temp!=node){
        previous=temp;
        temp=temp->next;
    }
    
    return previous;
}

// Assignment Operator Definition
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other){
    Node<T>* temp=other.head;
    if(this!=&other){
        this->append(temp->data);
        temp=temp->next;
    }
    return *this;
}

// Copy Constructor Definition
template<class T>
LinkedList<T>::LinkedList(const LinkedList&l){
    Node<T>* temp=l.head;
    while(temp!=NULL)
    {
        this->append(temp->data);
        temp=temp->next;
    }
}

template<class T>
Node<T>* LinkedList<T>::getHead(){
    return head;
}
