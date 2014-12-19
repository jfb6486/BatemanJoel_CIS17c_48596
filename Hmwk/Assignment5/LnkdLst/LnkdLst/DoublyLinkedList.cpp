//
//  DoublyLinkedList.cpp
//  LnkdLst
//
//  Created by Joel Bateman on 09/30/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "DoublyLinkedList.h"


template<class T>
void DoublyLinkedList<T>::addToHead(const T& element){
    head=new DoublyLinkedListNode(element, head);
    
    if (tail==NULL){
        tail=head;
    }
}

template<class T>
void DoublyLinkedList<T>::addToTail(const T& element){
    if(tail != NULL){
        tail = new DoublyLinkedListNode<T>(element, NULL, tail);
        tail->prev->next = tail;
    }
    else{
        head=tail=new DoublyLinkedListNode<T>(element);
    }
}

template<class T>
T DoublyLinkedList<T>::deleteFromHead(){
    T element = head->info;
    DoublyLinkedListNode *tmp = head;
    if (head == tail)
        head = tail = NULL;
    else
        head = head->next;
    delete tmp;
    return element;
}

template<class T>
T DoublyLinkedList<T>::deleteFromTail(){
    T element = tail->info;
    if (head == tail){
        delete head;
        head = tail = NULL;
    }
    else{
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }
    return element;
}

template<class T>
void DoublyLinkedList<T>::deleteNode(T element){
    if (head != NULL){
        if (head == tail && element == head->info){
            delete head;
            head = tail = NULL;
        }
        else if (element == head->info){
            DoublyLinkedListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        else{
            DoublyLinkedListNode *pred, *tmp;
            for(pred=head,tmp=head->next;
                tmp!=NULL &&!(tmp->info == element);
                pred=pred->next, tmp = tmp->next);
            if (tmp!=NULL){
                pred->next = tmp->next;
                if (tmp==tail)
                    tail=pred;
                delete tmp;
            }
        }
    }
}

template<class T>
bool DoublyLinkedList<T>::isEmpty(){
    return head == NULL;
}

template<class T>
bool DoublyLinkedList<T>::isInList(T element) const{
    DoublyLinkedListNode *tmp;
    for (tmp=head;tmp!=NULL&&!(tmp->info == element); tmp = tmp->next);
    return tmp!=NULL;
}