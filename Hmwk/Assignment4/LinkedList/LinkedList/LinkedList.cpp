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

template <class T>
T LinkedList<T>::peekFirst(){
    return head->data;
}

template <class T>
T LinkedList<T>::peekLast(){
    return tail->data;
}

template <class T>
void LinkedList<T>::insertBefore(T reference, T data){
    if (isEmpty())
        return;
    
    Node *currentNode = head;
    
    if (currentNode->data == reference){
        Node *n = new Node(data);
        n->next = currentNode->next;
        currentNode->next = n;
        return;
    }
    
    while (currentNode->next != NULL){
        if (currentNode->next->data == reference){
            Node *n = new Node(data);
            n->next = currentNode->next;
            currentNode->next = n;
            return;
        }
        
        currentNode = currentNode->next;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T reference, T data){
    if (isEmpty())
        return;
    
    Node *currentNode = head;
    
    if (currentNode->data == reference){
        Node *n = new Node(data);
        n->next = currentNode->next;
        currentNode->next = n;
        return;
    }
    
    while (currentNode != NULL){
        if (currentNode->data == reference){
            Node *n = new Node(data);
            n->next = currentNode->next;
            currentNode->next = n;
            return;
        }
        
        currentNode = currentNode->next;
    }
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return head == NULL;
}

template <class T>
void LinkedList<T>::prepend(T data){
    head = new Node(data, head);
    
    if (tail == NULL)
    {
        tail = head;
    }
}

template <class T>
void LinkedList<T>::append(T data){
    if (tail != NULL)
    {
        tail->next = new Node(data);
        tail = tail->next;
    }
    else
    {
        head = tail = new Node(data);
    }
}

template <class T>
int LinkedList<T>::deleteFromHead(){
    int entry = head->data;
    Node *tmp = head;
    
    if (head == tail){
        head = tail = NULL;
    }
    else{
        head = head->next;
    }
    
    delete tmp;
    return entry;
}

template <class T>
int LinkedList<T>::deleteFromTail(){
    int entry = tail->data;
    
    if (head == tail){
        delete head;
        head = tail = NULL;
    }
    else{
        Node *tmp;
        
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        
        delete tail;
        tail = tmp;
        tail->next = NULL;
    }
    
    return entry;
}

template <class T>
void LinkedList<T>::deleteNode(T data){
    if (head != NULL){
        if (head == tail && data == head->data){
            delete head;
            head = tail = NULL;
        }
        else if (data == head->data){
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        else{
            Node *pred, *tmp;
            
            for (pred = head, tmp = head->next;
                 tmp != NULL && !(tmp->data == data);
                 pred = pred->next, tmp = tmp->next);
            
            if (tmp != NULL){
                pred->next = tmp->next;
                if (tmp == tail)
                {
                    tail = pred;
                }
                
                delete tmp;
            }
        }
    }
}

template <class T>
bool LinkedList<T>::contains(T data){
    Node *tmp;
    int entry = data;
    
    for (tmp=head;tmp!=NULL&&!(tmp->data==entry);tmp=tmp->next);
    
    return tmp != NULL;
}

template <class T>
void LinkedList<T>::toString(){
    Node *currentNode = head;
    int counter = 0;
    
    if (currentNode == NULL){
        cout << "List is empty\n";
        return;
    }
    
    while (currentNode != NULL){
        cout << "Node " << ++counter << ": " << currentNode->data << '\n';
        currentNode = currentNode->next;
    }
}

