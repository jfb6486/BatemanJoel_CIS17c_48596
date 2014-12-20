//
//  Location.cpp
//  midtermProject
//
//  Created by Joel Bateman on 12/18/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "Location.h"

// Constructor
Location::Location(){
    
}

// Deconstructor
Location::~Location(){
    
}

void Location::addEntry(int n){
    if(count==maxSize){
        cout<<"Stops list is full"<<endl<<endl;
    }
    else{
        InfoNode *newTop = new InfoNode;
        
        if(top==NULL){
            newTop->ID=n;
            newTop->next=NULL;
            top=newTop;
            count++;
            cout<<"Stop Added"<<endl;
        }
        else{
            newTop->ID=n;
            newTop->next=top;
            top=newTop;
            count++;
            cout<<"Stop Added"<<endl;
        }
    }
}

void Location::deleteFirstStop(){
    if(top==NULL){
        cout<<"No stops in list"<<endl;
    }
    else{
        InfoNode *old=top;
        top=top->next;
        delete(old);
        count--;
        cout<<"Previous Stop Was Deleted from Stop Stack"<<endl;
    }
}

void Location::printStops(){
    int count=1;
    InfoNode *temp;
    temp=top;
    cout<<"Stop Stack"<<endl
    <<"==============="<<endl;
    if(temp==NULL){
        cout<<"Stack is empty"<<endl;
    }
    else if(temp!=NULL){
        while(temp!=NULL){
            string selectedStops = "";
            switch(temp->ID)
            {
                case 0:selectedStops = "Home";
                    preBuiltLocations.push_back(selectedStops);
                    break;
                case 1: selectedStops = "Chevron";
                    preBuiltLocations.push_back(selectedStops);
                    break;
                case 2: selectedStops = "Vons";
                    preBuiltLocations.push_back(selectedStops);
                    break;
                case 3: selectedStops = "Wingstop";
                    preBuiltLocations.push_back(selectedStops);
                    break;
                case 4: selectedStops = "Winco";
                    preBuiltLocations.push_back(selectedStops);
                    break;
                default: cout<<"Not in favorites location spots"<<endl;
                    break;
            }
            temp=temp->next;
        }
        for(list<string>::iterator it=preBuiltLocations.begin();it!=preBuiltLocations.end();it++){
            cout<<count++<<") "<<*it<<endl;
        }
    }
    cout<<"==============="<<endl;
    cout<<"Stops Printed"<<endl;
    preBuiltLocations.clear();
}

