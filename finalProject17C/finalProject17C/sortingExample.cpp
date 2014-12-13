//
//  sortingExample.cpp
//  finalProject17C
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//
#include "sortingExample.h"

void sortExample::execute(){
    srand(time(0));
    const int size = 100000;
    float t, t1, t2, t3, t4;
    int array[size], elements;
    cout << "Size of array: 100000" << endl;
    cout << "How many elements would you like to view: ";
    cin >> elements;
    
    // Bubble Sort
    cout << "Bubble Sort Executing..." << endl;
    random(array,size);
    bubbleSort(array,size);
    t = clock();
    printArray(array,elements);
    cout << "\nTime to finish Bubble Sort: " << t/1.0e3f
    << " seconds." << endl;
    cout << endl;
    cout << "Selection Sort Executing..." << endl;
    
    // Selection Sort
    random(array,size);
    selectSort(array,size);
    t1 = clock() - t;
    printArray(array,elements);
    cout << "\nTime to finish Selection Sort: " << t1/1.0e3f
    << " seconds." << endl;
    cout << endl;
   
    // Merge Sort
    cout << "Merge Sort Executing..." << endl;
    random(array,size);
    mergeSort(array,0,size-1);
    t2 = clock() - (t + t1);
    printArray(array,elements);
    cout << "\nTime to finish Merge Sort: " << t2/1.0e3f
    << " seconds." << endl;
    cout << endl;
    
    // Quick Sort
    cout << "Quick Sort Executing..." << endl;
    random(array,size);
    quickSort(array,0,size-1);
    t3 = clock() - (t + t1 + t2);
    printArray(array,elements);
    cout << "\nTime to finish Quick Sort: " << t3/1.0e3f
    << " seconds." << endl;
    cout << endl;
    
    // Heap Sort
    cout << "Heap Sort Executing..." << endl;
    random(array,size);
    heapSort(array,size);
    t4 = clock() - (t + t1 + t2 + t3);
    printArray(array,elements);
    cout << "\nTime to finish Heap Sort: " << t4/1.0e3f
    << " seconds." << endl;
    cout << endl;
    cout << endl << "Bubble Sort Execution time: O(n^2)" << endl;
    cout << "Selection Sort Execution time: O(n^2)" << endl;
    cout << "Merge Sort Execution time: O(nlog(n))" << endl;
    cout << "Quick Sort Execution time: O(nlog(n))" << endl;
    cout << "Heap Sort Execution time: O(nlog(n))" << endl;
    cout << "Fastest Executing algorithm: Heap Sort" << endl;
}

void sortExample::printArray(int a[],int p){
    for(int i = 0; i < p;i++)
        cout << a[i] << " ";
}

void sortExample::random(int a[], int n){
    for(int i = 0; i < n; i++)
        a[i] = rand()%1000 + 1;
}

void sortExample::bubbleSort(int a[], int n){
    int flag = 1;
    for(int i = 0; i < n; i++){
        flag = 0;
        for(int j = i + 1; j <
            n - 1;j++){
            if (a[i] > a[j]){
                swap(a[i],a[j]);
                flag = 1;
            }
        }
    }
}

void sortExample::swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void sortExample::selectSort(int a[], int n){
    int pos, temp;
    for(int i = 0; i < n;i++){
        pos = i;
        for(int j = i + 1; j < n - 1; j++){
            if(a[j] < a[pos])
                pos = j;
        }
        if(pos != i)
            swap(a[i],a[pos]);
    }
}

void sortExample::mergeSort(int* A, const int p, const int r){
    if (p < r){
        int q = (p+r)/2;
        mergeSort(A, p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

void sortExample::merge(int* A,int p,const int q, const int r){
    const int n_1=q-p+1;
    const int n_2=r-q;
    int* L = new int [n_1+1];
    int* R = new int [n_2+1];
    L[n_1]=0;
    R[n_2]=0;
    for(int i = 0; i < n_1; i++)
        L[i] = A[p+i];
    for (int j = 0; j < n_2; j++)
        R[j] = A[q+j+1];
    
    int i=0;
    int j=0;
    int k;
    for(k=p; k <= r && i < n_1 && j < n_2; ++k){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
    while (i < n_1) {A[k++] = L[i++];}
    while (j < n_2) {A[k++] = R[j++];}
}

void sortExample::quickSort(int a[], int first, int last ) {
    int pivotElement;
    if(first < last){
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
}

int sortExample::pivot(int a[], int first, int last) {
    int  p = first;
    int pivotElement = a[first];
    for(int i = first+1 ; i <= last ; i++){
        if(a[i] <= pivotElement){
            p++;
            swap(a[i], a[p]);
        }
    }
    swap(a[p], a[first]);
    return p;
}

void sortExample::heapSort(int A[], int length){
    int heapsize = length;
    buildheap(A, length);
    for (int i = length-1; i >=1; i--){
        swap(A[0], A[i]);
        heapsize--;
        heapify(A, heapsize, 0);
    }
}

void sortExample::buildheap(int A[], int length){
    for (int i = floor((length)/2); i >= 0;i--)
        heapify(A, length, i);
}

void sortExample::heapify(int A[], int heapsize, int root){
    int left = 2*root+1, right = 2*root +2, largest;
    if ( (left < heapsize) && (A[left] > A[root]))
        largest = left;
    else
        largest = root;
    if ( (right < heapsize) && (A[right] > A[largest]))
        largest = right;
    if (largest != root){
        swap(A[root], A[largest]);
        heapify(A, heapsize, largest);
    }
}
