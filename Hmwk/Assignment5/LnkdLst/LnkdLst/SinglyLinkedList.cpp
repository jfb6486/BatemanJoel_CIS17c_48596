//
//  SinglyLinkedList.cpp
//  LnkdLst
//
//  Created by Joel Bateman on 10/30/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "SinglyLinkedList.h"

template <class T>
bool SinglyLinkedList<T>::isEmpty(){
    return head == NULL;
}

template <class T>
T const SinglyLinkedList<T>::peekFirst(){
    return head->data;
}

template <class T>
T const SinglyLinkedList<T>::peekLast(){
    return tail->data;
}

template <class T>
void SinglyLinkedList<T>::prepend(T newEntry){
    head = new Node(newEntry, head);
    
    if (tail == NULL){
        tail = head;
    }
}

template <class T>
void SinglyLinkedList<T>::append(T newEntry){
    if (tail != NULL){
        tail->next = new Node(newEntry);
        tail = tail->next;
    }
    else{
        head = tail = new Node(newEntry);
    }
}

template <class T>
T SinglyLinkedList<T>::deleteFromHead(){
    T entry = head->data;
    Node *tmp = head;
    
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
    }
    
    delete tmp;
    return entry;
}

template <class T>
T SinglyLinkedList<T>::deleteFromTail(){
    T entry = tail->data;
    
    if (head == tail)
    {
        delete head;
        head = tail = NULL;
    }
    else
    {
        Node *tmp;
        
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        
        delete tail;
        tail = tmp;
        tail->next = NULL;
    }
    
    return entry;
}

template <class T>
void SinglyLinkedList<T>::deleteNode(T entry){
    if (head != NULL)
    {
        if (head == tail && entry == head->data)
        {
            delete head;
            head = tail = NULL;
        }
        else if (entry == head->data)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            Node *pred, *tmp;
            
            for (pred = head, tmp = head->next;
                 tmp != NULL && !(tmp->data == entry);
                 pred = pred->next, tmp = tmp->next);
            
            if (tmp != NULL)
            {
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
bool SinglyLinkedList<T>::contains(T entry){
    Node *tmp;
    
    for (tmp = head; tmp != NULL && !(tmp->data == entry); tmp = tmp->next);
    
    return tmp != NULL;
}