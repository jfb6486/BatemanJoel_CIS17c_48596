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

using namespace std;

class InfoNode{
public:
    int ID=0;
    InfoNode* next;
};

class Location{
public:
    Location();
    ~Location();
    
    InfoNode *top;
    int count; // head
    int maxSize=4;
    list<string> preBuiltLocations;
        
    void addEntry(int);
    void deleteFirstStop();
    void printStops();
};
#endif /* defined(__midtermProject__Contact__) */
