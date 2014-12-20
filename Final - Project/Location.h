//
//  Location.h
//  midtermProject
//
//  Created by Joel Bateman on 12/18/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __midtermProject__Contact__
#define __midtermProject__Contact__

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

#include "HashTable.h"

using namespace std;

class InfoNode{
public:
    string name;
    int ID=0;
    InfoNode* next;
    
    const void printInfo(){
        cout<<"ID "<<ID<<endl;
        cout<<"Name "<<name<<endl;
        cout<<"-------------------"<<endl;
    }
};

class Location{
public:
    Location();
    ~Location();
    
    InfoNode *top=NULL;
    int count=0; // head
    int maxSize=4;
    list<string> preBuiltLocations;
        
    void addEntry(int);
    void deleteFirstStop();
    void printStops();
    void fillList();
    
    HashTable<InfoNode *>* getLocations() const;
    InfoNode* findLocationID(int ID);
    bool addNode(int ID, InfoNode* infoNode);
    bool deleteNode(int ID);

private:
    HashTable<InfoNode *> *locations;
    
};
#endif /* defined(__midtermProject__Contact__) */
