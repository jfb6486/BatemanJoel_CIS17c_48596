//
//  DoublyLinkedList.h
//  LnkdLst
//
//  Created by Joel Bateman on 09/30/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __LnkdLst__DoublyLinkedList__
#define __LnkdLst__DoublyLinkedList__

#include <stdio.h>

template<class T>
class DoublyLinkedListNode
{
public:
    DoublyLinkedListNode(){
        next=prev=NULL;
    }
    
    DoublyLinkedListNode(const T& element, DoublyLinkedListNode *n=NULL, DoublyLinkedListNode *p=NULL){
        info = element; next = n; prev = p;
    }
    
    T info;
    DoublyLinkedListNode *next, *prev;
};

template<class T>
class DoublyLinkedList{
public:
    DoublyLinkedList(){head=tail=NULL;}
    
    void addToHead(const T&);
    void addToTail(const T&);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(T);
    bool isEmpty();
    bool isInList(T) const;
    
private:
    DoublyLinkedListNode<T> *head, *tail;
};

#endif /* defined(__LnkdLst__DoublyLinkedList__) */
