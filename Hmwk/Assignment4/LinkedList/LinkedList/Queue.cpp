////
////  Queue.cpp
////  LinkedList
////
////  Created by Joel Bateman on 11/13/14.
////  Copyright (c) 2014 Joel Bateman. All rights reserved.
////
//
//#include <iostream>
//#include "Queue.h"
//#include <cstddef>
//#include <cstdlib>
//
//using namespace std;
//
//namespace queuesavitch{
//    
//    //Default constructor
//    //Uses cstddef
//    Queue::Queue() : front(NULL), back(NULL){
//        //Intentionally left empty
//    }
//    
//    //Copy constructor
//    Queue::Queue(const Queue& a_queue){
//        
//        //If a_queue is empty, front and back set to NULL
//        if(a_queue.front==NULL){
//            front=NULL;
//            back=NULL;
//        }// end if
//        else{
//            QueueNode* temp=new QueueNode;
//            temp=a_queue.front;
//            char newData;
//            
//            while(temp!=NULL){
//                newData=a_queue.front->data;
//                add(newData);
//                temp=temp->link;
//            }
//            back=a_queue.back;
//        }// end else
//    }// end constructor
//    
//    //Deconstructor
//    Queue::~Queue(){
//        char next;
//        while(!empty()){
//            next=remove();
//        }
//    }
//    
//    //Uses cstddef
//    void Queue::add(char item){
//        
//        //Create the new link to add
//        QueueNode *newLink=new QueueNode;
//        
//        //Set data equal to item being passed in
//        //Set newLink->link to NULL
//        newLink->data=item;
//        newLink->link=NULL;
//        
//        if(front==NULL){
//            front=newLink;
//            back=newLink;
//        }//end if
//        else{
//            back->link=newLink;
//            back=back->link;
//        }//end else
//    }//end add
//    
//    char Queue::remove(){
//        if(empty()){
//            cout<<"Error: Removing at item from an empty queue.\n";
//            exit(1);
//        }
//        
//        char result = front->data;
//        
//        QueueNodePtr discard;
//        discard=front;
//        front=front->link;
//        if(front==NULL){ //if you removed the last node
//            back=NULL;
//        }
//        
//        delete discard;
//        
//        return result;
//    }//end remove
//    
//    bool Queue::empty() const{
//        //front==NULL would also work here
//        return(back==NULL);
//    }//end empty
//}//queuesavitch
//
//
