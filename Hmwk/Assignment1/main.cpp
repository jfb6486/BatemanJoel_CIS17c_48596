//
//  main.cpp
//  TriangularMatrix
//
//  Created by Joel Bateman on 8/27/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function Prototypes
int* fillArray(int);
int** fillArray(int, int);
int** fillArray(int, int*);
void printArray(int*,int,int);
void printArray(int**,int,int);
void printArray(int**,int,int*);
void destroy(int *);
void destroy(int**, int);

//Execution begins here
int main(int argc, const char** argv){
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare the 2-D Array
    int rows=5,cols=10;
    int cls=rows,perLine=10;
    
    int** array=fillArray(rows, cols);
    int* colAry=fillArray(cls);
    int** triAry=fillArray(rows,colAry);

    //Print func. #1
    printArray(array, rows, cols);
    //Print func. #2
    printArray(colAry, cls, perLine);
    //Print func. #3
    printArray(triAry, rows, colAry);

    //Delete func. #1
    destroy(array, rows);
    //Delete func. #2
    destroy(colAry);
    //Delete func. #3
    destroy(triAry, rows);

    // Exit stage right
    return 0;
}

//Print func. #1
void printArray(int** array, int rows, int cols){
    cout<<"\n";
    cout<<"Print func. 1 "<<"\n";
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<array[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

//Print func. #2
void printArray(int* array, int cols, int perLine){
    cout<<"\n";
    cout<<"Print func. 2 "<<"\n";
    for(int col=0;col<cols;col++){
        cout<<array[col]<<" ";
        // *Note to self | Debug this part
        if(col%perLine==(perLine-1)){
            cout<<"\n";
        }
        cout<<"\n";
    }
}

//Print func. #3
void printArray(int** array, int rows, int *colAry){
    cout<<"\n";
    cout<<"Print func. 3 "<<"\n";
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            cout<<array[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

// Fill array func. #1
int* fillArray(int cols){
    //Declare 1-D array
    int* array=new int[cols];
    //Fill the array with 2 digit numbers
    for(int col=0; col<cols;col++){
        array[col]=rand()%9+2;
    }
    return array;
}

// Fill array func. #2
int** fillArray(int rows, int cols){
    //Declare the 2-D Array
    int** array = new int*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new int[cols];
    }
    for(int row=0; row<rows;row++){
        for(int col=0;col<cols;col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}

//Fill array func. #3
int** fillArray(int rows, int* colAry){
    //Declare the 2-D Array
    int** array=new int* [rows];
    for(int row=0; row<rows;row++){
        array[row]=new int[colAry[row]];
    }
    //Fill the array with random 2 digits numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}

void destroy(int* array){
    //Destroy row pointers
    delete [] array;
}

void destroy(int** array, int rows){
    //Destroy cols
    for(int row=0;row<rows;row++){
        delete [] array[row];
    }
    //Destroy row pointers
    delete [] array;
}


