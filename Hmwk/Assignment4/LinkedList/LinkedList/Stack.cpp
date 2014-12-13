//
//  Stack.cpp
//  LinkedList
//
//  Created by Joel Bateman on 11/13/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include <cstddef>

using namespace std;

namespace stacksavitch{
    
    //Uses cstddef
    Stack::Stack() : top(NULL){
        //Intentionally left empty
    }
    
    Stack::Stack(const Stack& a_stack){
        if(a_stack.top==NULL){
            top=NULL;   // original list is empty
        }
        else{
            // copy first node
            top=new StackFrame;
            top->data=a_stack.top->data;
            
            // copy rest of list
            StackFrame *newPtr=top; // new node pointer
            for(StackFrame *origPtr=a_stack.top->link;origPtr!=NULL;
                origPtr=origPtr->link){
                newPtr->link=new StackFrame;
                newPtr=newPtr->link;
                newPtr->data=origPtr->data;
            }
            newPtr->link=NULL; // tail
        }
    }
    
    Stack::~Stack(){
        char next;
        while(!empty()){
            next=pop(); // pop calls delete
        }
    }
    
    //Uses cstddef
    bool Stack::empty() const{
        return(top==NULL);
    }
    
    void Stack::push(char the_symbol){
        
        StackFrame *newPtr=new StackFrame;
        
        // set data portion of new node
        newPtr->data=the_symbol;
        
        //insert the new node
        newPtr->link=top;// newPtr->next pointer points to top
        top=newPtr;
    }
    
    //Uses iostream
    char Stack::pop(){
        
        if(empty()){
            cout<<"Error: popping an empty stack. \n";
            exit(1);
        }
        
        char result=top->data;
        
        StackFramePtr temp_ptr;
        temp_ptr=top;
        top=top->link;
        
        delete temp_ptr;
        
        return result;
    }
}// stacksavitch