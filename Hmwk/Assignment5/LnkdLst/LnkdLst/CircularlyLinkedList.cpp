//
//  CircularlyLinkedList.cpp
//  LnkdLst
//
//  Created by Joel Bateman on 09/24/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "CircularlyLinkedList.h"

template<class T>
void CSLList<T>::addToHead(const T &element)
{
    if (isEmpty()){
        tail = new CSLLNode(element);
        tail->next = tail;
    }
    else{
        tail->next = new CSLLNode(element, tail->next);
    }
}

template<class T>
void CSLList<T>::addToTail(const T &element){
    if (isEmpty()){
        tail = new CSLLNode(element);
        tail->next = tail;
    }
    else{
        tail->next = new CSLLNode(element, tail->next);
        tail = tail->next;
    }
}

template<class T>
T CSLList<T>::deleteFromHead(){
    CSLLNode *tmp = tail->next;
    tail->next = tmp->next;
    delete tmp;
}

template<class T>
T CSLList<T>::deleteFromTail(){
    CSLLNode *tmp = tail;
    while (tmp->next != tail)
        tmp = tmp->next;
    tail = tmp;
    delete tmp->next;
    tmp->next = NULL;
}

template<class T>
void CSLList<T>::deleteNode(T element){
    if (tail != NULL)
    {
        if (element == tail->info)
        {
            delete tail;
            tail = NULL;
        }
        else
        {
            CSLLNode *pred, *tmp;
            for(pred = tail, tmp = tail->next;
                 tmp != NULL && !(tmp->info == element);
                 pred = pred->next, tmp = tmp->next);
            if (tmp != NULL){
                pred->next = tmp->next;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
    }
}

template<class T>
bool CSLList<T>::isEmpty(){
    return tail == NULL;
}

template<class T>
bool CSLList<T>::isInList(T element) const{
    CSLLNode *tmp;
    for (tmp = tail; tmp != NULL && !(tmp->info == element); tmp = tmp->next);
    return tmp != NULL;
}