//
//  Queue.h
//  LinkedList
//
//  Created by Joel Bateman on 11/13/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

#ifndef __LinkedList__Queue__
#define __LinkedList__Queue__

#include <stdio.h>

namespace queuesavitch{
    
    struct QueueNode{
        char data;
        QueueNode *link;
    };
    
    typedef QueueNode* QueueNodePtr;
    
    class Queue{
    public:
        //Initializes the object to an empty queue
        Queue();
        
        //Copy consturctor
        Queue(const Queue& a_queue);
        
        //Deconstructor
        ~Queue();
        
        //Post condition: item has been added to back of the quere
        void add(char item);
        
        //Pre condition: the queue is not empty
        //Returns the item at the front of the queue
        //removes the item from the queue
        char remove();
        
        //Return true if the queue is empty. Returns false otherwise
        bool empty() const;
        
    private:
        //Points to the head of the Linked List
        //Items are removed at the head
        QueueNodePtr front=NULL;
        
        //Points to the node at the other end
        //of the Linked List. Items are added from this end
        QueueNodePtr back=NULL;
        
    };
}//queuesavitch
#endif /* defined(__LinkedList__Queue__) */
