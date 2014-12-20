//
//  weightedGraph.cpp
//  midtermProject
//
//  Created by Joel Bateman on 12/18/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "weightedGraph.h"
#include <iomanip>

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int weightedGraph::minKey(int key[], bool mstSet[]){
    // Initialize min value
    int min = INT_MAX, min_index=0;
    
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    
    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void weightedGraph::printMST(int parent[], int n, int graph[V][V]){
    cout<<"   2    3"<<endl
    <<"(0)--(1)--(2)"<<endl
    <<" |   / \   |"<<endl
    <<"6| 8/   \5  |7"<<endl
    <<" | /     \ |"<<endl
    <<"(3)-------(4)"<<endl
    <<"      9"<<endl;
    cout<<"================================="<<endl<<
    "     Minimum Spanning Tree"<<endl<<
    "================================="<<endl;
    cout<<"Start"<<setw(10)<<"End "<<setw(19)<<"Distance\n";
    for (int i = 1; i < V; i++){
        int startAirPortNumber = parent[i];
        int endAirPortNumber = i;
        string airPort = "";
        //        cout << parent[i] <<" - "<< i << "  " <<graph[i][parent[i]]<<endl;
        switch(startAirPortNumber)
        {
            case 0:airPort = "Home(0)";
                break;
            case 1: airPort = "Chevron(1)";
                break;
            case 2: airPort = "Vons(2)";
                break;
            case 3: airPort = "Wingstop(3)";
                break;
            case 4: airPort = "Winco(4)";
                break;
        }
        
        cout <<left<<setw(10)<<airPort<<" ";
        
        switch(endAirPortNumber)
        {
            case 0:airPort = "Home(0)";
                break;
            case 1: airPort = "Chevron(1)";
                break;
            case 2: airPort = "Vons(2)";
                break;
            case 3: airPort = "Wingstop(3)";
                break;
            case 4: airPort = "Winco(4)";
                break;
        }
        cout <<setw(12)<<airPort<<"  "<<setw(10)<<graph[i][parent[i]]<<endl;
    }
    //        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void weightedGraph::primMST(int graph[V][V]){
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST
    
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    
    // Always include first 1st vertex in MST.
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST
    
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++){
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)
            
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    
    
    // print the constructed MST
    printMST(parent, V, graph);
}