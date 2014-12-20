//
//  dijkstraAlgorithm.h
//  weightedGraph
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __weightedGraph__dijkstraAlgorithm__
#define __weightedGraph__dijkstraAlgorithm__

#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

// Number of vertices in the graph
#define V 5

class dijkstraAlgorithm{
public:
    dijkstraAlgorithm(){}
    ~dijkstraAlgorithm(){}
    
    int minDistance(int[], bool[]);
    void printSolution(int[], int);
    void dijkstra(int[][V], int);
};
#endif

