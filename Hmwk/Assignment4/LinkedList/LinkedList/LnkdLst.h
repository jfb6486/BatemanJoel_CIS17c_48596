//
//  LnkdLst.h
//  LinkedList
//
//  Created by Joel Bateman on 9/24/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

#ifndef LinkedList_LnkdLst_h
#define LinkedList_LnkdLst_h

#include <string>
#include <iostream>

using namespace std;

class LnkdLst{
private:
    int size;
    struct Node{
        int data;
        Node *next;
    };
    
public:
    LnkdLst(int n){
        size=n;
    }
    
    void setsize(){
        
    }
    
    void append(int);
    string toString();
    virtual ~LnkdLst();
    
    Node *head;
    Node *worker;
};
#endif	/* LNKDLST_H */

