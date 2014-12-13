//
//  sortingExample.h
//  finalProject17C
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __finalProject17C__sortingExample__
#define __finalProject17C__sortingExample__

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class sortExample{
public:
    void execute();
    void random(int [], int);
    void swap(int&, int&);
    void bubbleSort(int [], int);
    void selectSort(int [], int);
    void merge(int*,int,const int, const int);
    void mergeSort(int*, const int, const int);
    void quickSort(int [], int, int);
    int pivot(int [], int, int);
    void heapSort(int [], int);
    void buildheap(int [], int);
    void heapify(int [], int, int);
    void printArray(int [], int);
};

#endif /* defined(__finalProject17C__sortingExample__) */
