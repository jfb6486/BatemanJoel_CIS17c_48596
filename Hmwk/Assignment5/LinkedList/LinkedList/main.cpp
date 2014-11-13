//
//  main.cpp
//  LinkedList
//
//  Created by Joel Bateman on 9/24/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "LinkedList.h"
#include "LinkedList.cpp"


int main(int argc, char** argv) {
        
    //Create a linked list
    LinkedList<int> list;
    
    //Append 3 more chains
    int clinks=3;

    for(int i=1;i<=clinks;i++){
        int insert=rand()%20;
        list.append(insert);
    }
    //Print the data
    cout<<list.toString()<<endl;
    
    for(int j=3;j<=clinks+3;j++){
        int insert=rand()%20;
        list.prepend(list.getHead(), insert);
    }
    
    cout<<list.toString()<<endl;

    int insertAtNode=0;
    int newValue=0;
    
    cout<<"Insert Before Test: "<<endl
    <<"Enter Node ID to insert before:";
    cin>>insertAtNode;
    cout<<endl;
    cout<<"Value at new node?";
    cin>>newValue;
    list.insertBefore(insertAtNode, newValue);
    cout<<list.toString()<<endl;
    
    cout<<"Insert After Test: "<<endl
    <<"Enter Node ID to after:";
    cin>>insertAtNode;
    cout<<endl;
    cout<<"Value at new node?";
    cin>>newValue;
    list.insertAfter(insertAtNode, newValue);
    cout<<list.toString()<<endl;

    list.getFirst();
    cout<<endl;
    list.getLast();
    cout<<endl;
    
    int read;
    cout<<"Extract node Test"<<endl
    <<"Which node ID do you want to extract data from?";
    cin>>read;
    cout<<"Data at Node ID "<< read <<" contains: ";
    list.extractData(read);
    
    //Exit stage right!
    return 0;
}