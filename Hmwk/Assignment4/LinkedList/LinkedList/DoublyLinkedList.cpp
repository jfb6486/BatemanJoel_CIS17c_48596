////
////  DoublyLinkedList.cpp
////  LinkedList
////
////  Created by Joel Bateman on 11/13/14.
////  Copyright (c) 2014 Joel Bateman. All rights reserved.
////
//
//#include "DoublyLinkedList.h"
//#include <stdio.h>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
////Default constructor
//DoublyLinkedList::DoublyLinkedList() : size(NULL), head(NULL){
//    //Intentionally left empty
//}
//
////Copy constructor
//DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& a_list){
//    
//}
//
////Deconstructor
//DoublyLinkedList::~DoublyLinkedList(){
//    if(size>-1){
//        clear();
//    }
//}
//
//void DoublyLinkedList::insertNode(int data){
//    Node *newNode=new Node;
//    newNode->data=data;
//
//    if(size>-1){
//        newNode->next=head;
//        newNode->prev=tail;
//        tail->next=newNode;
//        tail=newNode;
//        size++;
//    }
//    else if(size==1){
//        head=newNode;
//        head->next=newNode;
//        head->prev=newNode;
//        tail=newNode;
//        tail->next=newNode;
//        tail->prev=newNode;
//        size=0;
//    }
//}
//
//void DoublyLinkedList::deleteNode(int position){
//    if(position<=size){
//        Node *temp=tail;
//        for(int i=0;i<=position;i++){
//            temp=temp->next;
//        }
//        temp->prev->next=temp->next;
//        temp->prev->next=temp->prev;
//        delete temp;
//        size--;
//    }
//}
//
//void DoublyLinkedList::printList(){
//    
//    if(head==NULL){
//        cout<<"Empty List!";
//        return;
//    }
//    
//    Node *temp=head;
//    
//    while(temp!=NULL){
//        cout<<temp->data<<"\t";
//        temp=temp->next;
//    }
//    cout<<endl;
//}
//
//void DoublyLinkedList::clear(){
//    Node *temp=head;
//    while(size>-1){
//        Node *tbdTemp=temp;
//        temp=temp->next;
//        delete tbdTemp;
//    }
//}