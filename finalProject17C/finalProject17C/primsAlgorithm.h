//
//  primsAlgorithm.h
//  weightedGraph
//
//  Created by Joel Bateman on 12/11/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __weightedGraph__primsAlgorithm__
#define __weightedGraph__primsAlgorithm__

#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

// Number of vertices in the graph
#define V 7
class primsAlgorithm{
public:
    primsAlgorithm(){}
    ~primsAlgorithm(){}
    
    int minKey(int[], bool[]);
    void printMST(int[], int, int[][V]);
    void primMST(int[][V]);
};
#endif
