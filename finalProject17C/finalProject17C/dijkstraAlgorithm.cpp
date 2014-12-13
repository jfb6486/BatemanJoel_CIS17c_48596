//
//  dijkstraAlgorithm.cpp
//  weightedGraph
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "dijkstraAlgorithm.h"

// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int dijkstraAlgorithm::minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index=0;
    
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

// A utility function to print the constructed distance array
void dijkstraAlgorithm::printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++){
        int endAirPortNumber = dist[i];
        int startAirPortNumber = i;
        string airPort = "";
//         cout<< i <<"        "<< dist[i] << endl;
        switch(startAirPortNumber)
        {
            case 0:airPort = "SFO";
                break;
            case 1: airPort = "ORD";
                break;
            case 2: airPort = "JFK";
                break;
            case 3: airPort = "DFW";
                break;
            case 4: airPort = "MIA";
                break;
            case 5: airPort = "LAX";
                break;
            case 6: airPort = "BOS";
                break;
        }
        
        cout << airPort <<"      ";
        
        switch(endAirPortNumber)
        {
            case 0:airPort = "SFO";
                break;
            case 1: airPort = "ORD";
                break;
            case 2: airPort = "JFK";
                break;
            case 3: airPort = "DFW";
                break;
            case 4: airPort = "MIA";
                break;
            case 5: airPort = "LAX";
                break;
            case 6: airPort = "BOS";
                break;
        }
        cout <<endAirPortNumber<<endl;
    }
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstraAlgorithm:: dijkstra(int graph[][V], int src)
{
    int dist[V];     // The output array.  dist[i] will hold the shortest
    // distance from src to i
    
    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet);
        
        // Mark the picked vertex as processed
        sptSet[u] = true;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    
    // print the constructed distance array
    printSolution(dist, V);
}