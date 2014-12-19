//
//  LinkedListStack.h
//  LnkdLst
//
//  Created by Joel Bateman on 10/30/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "SinglyLinkedList.h"

#ifndef LnkdLst_LinkedListStack_h
#define LnkdLst_LinkedListStack_h

template <class T>
class LinkedListStack
{
public:
    LinkedListStack(){ }
    ~LinkedListStack(){ }
    
    void clear(){ }
    
    bool isEmpty(){
        return list.isEmpty();
    }
    
    void push(T element){
        list.append(element);
    }
    
    T pop(){
        return list.deleteFromTail();
    }
    
    T peek(){
        return list.peekLast();
    }
    
private:
    SinglyLinkedList<T> list;
};

#endif
