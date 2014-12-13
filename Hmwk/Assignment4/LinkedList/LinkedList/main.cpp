//
//  main.cpp
//  LinkedList
//
//  Created by Joel Bateman on 9/24/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

//System Libraries
#include <iostream>
#include <queue>
#include <list>

//Our Library
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Stack.h"
#include "Queue.h"
#include "DoublyLinkedList.h"

priority_queue<char> q1;

using namespace std;
using namespace stacksavitch;
using namespace queuesavitch;

int main(int argc, char** argv) {
    
    // Linked List Testing
    //Create a linked list
//    LinkedList<int> list;
//    
//    //Append 3 more chains
//    int clinks=3;
//
//    for(int i=1;i<=clinks;i++){
//        int insert=rand()%20;
//        list.append(insert);
//    }
//    //Print the data
//    cout<<list.toString()<<endl;
//    
//    for(int j=3;j<=clinks+3;j++){
//        int insert=rand()%20;
//        list.prepend(list.getHead(), insert);
//    }
//    
//    cout<<list.toString()<<endl;
//
//    int insertAtNode=0;
//    int newValue=0;
//    
//    cout<<"Insert Before Test: "<<endl
//    <<"Enter Node ID to insert before:";
//    cin>>insertAtNode;
//    cout<<endl;
//    cout<<"Value at new node?";
//    cin>>newValue;
//    list.insertBefore(insertAtNode, newValue);
//    cout<<list.toString()<<endl;
//    
//    cout<<"Insert After Test: "<<endl
//    <<"Enter Node ID to after:";
//    cin>>insertAtNode;
//    cout<<endl;
//    cout<<"Value at new node?";
//    cin>>newValue;
//    list.insertAfter(insertAtNode, newValue);
//    cout<<list.toString()<<endl;
//
//    list.getFirst();
//    cout<<endl;
//    list.getLast();
//    cout<<endl;
//    
//    int read;
//    cout<<"Extract node Test"<<endl
//    <<"Which node ID do you want to extract data from?";
//    cin>>read;
//    cout<<"Data at Node ID "<< read <<" contains: ";
//    list.extractData(read);
    // End of Linked List Testing
    
    
    // Stack testing
//    Stack s;
//    char next, ans;
//    
//    do{
//        cout<<"Enter a word: ";
//        cin.get(next);
//        while (next!='\n'){
//            s.push(next);
//            cin.get(next);
//        }
//        
//        cout<<"written backwords that is: ";
//        while(!s.empty()){
//            cout<<s.pop();
//        }
//        cout<<endl;
//        
//        cout<<"Again?(y/n): ";
//        cin>>ans;
//        cin.ignore(10000, '\n');
//    }while(ans!='n'&&ans!='N');
    
    // Queue testing
//    Queue q;
//    char next, ans;
//    
//    do{
//        cout<<"Enter a word: ";
//        cin.get(next);
//        while (next!='\n'){
//            q.add(next);
//            cin.get(next);
//        }
//        
//        cout<<"You entered: ";
//        while(!q.empty()){
//            cout<<q.remove();
//        }
//        cout<<endl;
//        
//        cout<<"Again?(y/n): ";
//        cin>>ans;
//        cin.ignore(10000, '\n');
//    }while(ans!='n'&&ans!='N');
    
    DoublyLinkedList d;
    int t;
    cout<<"Enter the number of test cases\n";
    cin>>t;
    cout<<"Enter Quieres in this format: \n"
        <<"For Insertion: \t I Data \n"
        <<"\tEx:\tI 25 \n";
    cout<<"For Deletion: \t D Position \n";
    cout<<"\tEx:\tD 2 \n\n";
    
    while(t--){
        char c;
        int a;
        cout<<"Print query: \t";
        cin>>c;
        
        if(c=='I'){
            cin>>a;
            d.insertNode(a);
        }
        else if(c=='D'){
            cin>>a;
            d.deleteNode(a);
        }
        d.printList();
    }
    
    //Exit stage right!
    return 0;
}