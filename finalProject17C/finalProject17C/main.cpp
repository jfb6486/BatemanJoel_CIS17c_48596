//
//  main.cpp
//  finalProject17C
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include <iostream>

// Included classes
#include "checkOut.h"
#include "dijkstraAlgorithm.h"
#include "primsAlgorithm.h"
#include "HashTable.h"
#include "stackAlgorithm.h"
#include "HashTable.h"
#include "sortingExample.h"

// ==================================================================
// Main : Execution begins here
// ==================================================================
int main(int argc, const char * argv[]){

    int questionChoice;
    bool stay=true;
    
    do{
        cout<<"Welcome to Joel's Final for C++ Data Structures"<<endl
        <<"Enter(1, 2, 3, 4, 5, 6) for the respective question or 9 to exit\n";
        cout<<"Choice:";
        cin>>questionChoice;
        
        switch (questionChoice){
                // Hashing
            case 1:{
                string file = "initials.txt";
                int const numOfInitials = 3;
                int const SIZE = 1000;
                
                HashTable table(SIZE);
                
                table.generateInitials(file, numOfInitials, SIZE);
                table.processFile(file);
                table.printStats();
                
                //Loop table.find(somestring) to measure search time in this hash table
                int loopSize = 100000;
                clock_t begin = clock();
                for (int i = 0; i < loopSize; i++)
                {
                    table.find("ZSJ");
                }
                clock_t end = clock();
                double delta_time = double(end - begin) / CLOCKS_PER_SEC;
                cout << "Search time in " << loopSize << " loops: " << delta_time << " CPU time\n\n";
                break;
            }
                // Stacks
            case 2:{
                stackAlgorithm s;
                s.execute();
                break;
            }
                // Queues
            case 3:{
                checkOut c;
                c.replicate();
                break;
            }
                // Sorting
            case 4:{
                sortExample e;
                e.execute();
                break;
            }
                // Binary Trees
            case 5:{
                break;
            }
                // Weighted Graph
            case 6:{
                primsAlgorithm p;
                dijkstraAlgorithm d;
                int graph[V][V] =
                {
                    { 0, 1846, 0, 1464, 0, 337, 2704 },
                    { 1846, 0, 740, 802, 0, 0, 867   },
                    { 0, 740, 0, 0, 1090, 0, 187 },
                    { 1464, 802, 0, 0, 1121, 1235, 0},
                    { 0, 0, 1090, 1121, 0, 2342, 1258},
                    { 337, 0, 0, 1235, 2342, 0, 0},
                    { 2704, 867, 187, 0, 1258, 0, 0}
                };
                // Minimum spanning tree
                p.primMST(graph);
                cout<<endl;
                // Shortest distance
                d.dijkstra(graph, 0);
                break;
            }
            case 9:{
                stay=false;
                break;
            }
            default:{
                cout<<"Not a valid entry. Please enter (1, 3, 4, 6, 8)";
                break;
            }
        }
    } while(stay);
    cout<<"Thankyou for using Joel's Final for C++ Data Structures\n";
  
    return 0;
}
