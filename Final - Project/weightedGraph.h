//
//  weightedGraph.h
//  midtermProject
//
//  Created by Joel Bateman on 12/18/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __midtermProject__weightedGraph__
#define __midtermProject__weightedGraph__

#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

// Number of vertices in the graph
#define V 5

class weightedGraph{
public:
    int minKey(int[],bool[]);
    void printMST(int[], int, int[V][V]);
    void primMST(int[V][V]);
};
#endif /* defined(__midtermProject__weightedGraph__) */
