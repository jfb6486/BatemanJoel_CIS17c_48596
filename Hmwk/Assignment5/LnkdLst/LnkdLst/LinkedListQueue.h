//
//  LinkedListQueue.h
//  LnkdLst
//
//  Created by Joel Bateman on 10/30/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "SinglyLinkedList.h"

#ifndef LnkdLst_LinkedListQueue_h
#define LnkdLst_LinkedListQueue_h

template <class T>
class LinkedListQueue
{
public:
    LinkedListQueue(){ }
    ~LinkedListQueue(){ }
    void clear(){ }
    
    bool isEmpty(){
        return list.isEmpty();
    }
    
    void enqueue(T element){
        list.append(element);
    }
    
    T dequeue(){
        return list.deleteFromHead();
    }
    
    T peek(){
        return list.peekFirst();
    }
    
private:
    SinglyLinkedList<T> list;
};

#endif
