////
////  Stack.h
////  LinkedList
////
////  Created by Joel Bateman on 11/13/14.
////  Copyright (c) 2014 Joel Bateman. All rights reserved.
////
//
//#ifndef LinkedList_Stack_h
//#define LinkedList_Stack_h
//
//namespace stacksavitch{
//    
//    struct StackFrame{
//        char data;
//        StackFrame *link;
//    };
//    
//    typedef StackFrame* StackFramePtr;
//    
//    class Stack{
//    public:
//        // Initializs the object to an empty stack
//        Stack();
//        
//        // Copy constructor
//        Stack(const Stack& a_stack);
//        
//        // Destroys the stack and frees all memory
//        ~Stack();
//
//        // Post condition: The symbol has been added to the stack
//        void push(char the_symbol);
//        
//        // Post condition: The stack is not empty
//        // Returns the top symbol on the stack and removes that
//        // that top symbol
//        char pop();
//        
//        // Returns true if the stack is empty
//        // Returns false otherwise
//        bool empty() const;
//        
//    private:
//        StackFramePtr top;
//    };
//}//stacksavitch
//#endif
