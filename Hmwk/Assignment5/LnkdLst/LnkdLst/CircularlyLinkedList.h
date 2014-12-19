//
//  CircularlyLinkedList.h
//  LnkdLst
//
//  Created by Joel Bateman on 09/24/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __LnkdLst__CircularlyLinkedList__
#define __LnkdLst__CircularlyLinkedList__

#include <stdio.h>

template<class T>
class CSLLNode{
public:
    CSLLNode(){next = NULL;}
    CSLLNode(const T& element, CSLLNode *n = NULL)
    {info=element;next=n;}
    T info;
    CSLLNode *next;
};

template<class T>
class CSLList
{
public:
    CSLList(){tail = NULL;}
    ~CSLList();
    
    void addToHead(const T&);
    void addToTail(const T&);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(T);
    bool isEmpty();
    bool isInList(T) const;
    
private:
    CSLLNode *tail;
};

#endif /* defined(__LnkdLst__CircularlyLinkedList__) */

