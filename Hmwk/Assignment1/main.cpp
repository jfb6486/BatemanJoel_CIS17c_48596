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
#include <iomanip>

using namespace std;

template<class T>
class myArrays{
private:
    // myArray pointers
    T** array;
    int* colAry;
    T** triAry;
    
    // Variable declarations
    int rows,cols;
    int cls, perLine;
    
public:
    // Default constructor
    myArrays(){rows=0; cols=0;}
    
    // Constructor declaration
    myArrays(int, int);
    
    // Deconstructor declaration
    ~myArrays();
    
    // Rows accessor
    int getRows(){
        return rows;
    }
    
    // Cols accessor
    int getCols(){
        return cols;
    }
    
    // Function Prototypes
    void myArraysBuilder(int, int);
    void fillArrayOne();
    void printArrayOne();
    void fillArrayTwo();
    void printArrayTwo();
    void fillArrayThree();
    void printArrayThree();
    void destroyTwo();
    void destroyOne();
}; // End of myArrays header

// Execution begins here
int main(int argc, char** argv){
    
    myArrays<int> i(5, 10);
    // Func. call to myArraysBuilder
    i.myArraysBuilder(i.getRows(), i.getCols());
    
    myArrays<float> f(5, 10);
    // Func. call to myArraysBuilder
    f.myArraysBuilder(f.getRows(), f.getCols());
    
    myArrays<char> c(5,10);
    // Func. call to myArraysBuilder
    c.myArraysBuilder(c.getRows(), c.getCols());
    
    return 0; // Exit stage left
} // End of main

// Constructor
template <class T>
myArrays<T>::myArrays(int nRows, int nCols){
    rows=nRows;
    cols=nCols;
    cls=nRows;
    perLine=nCols;
} // End of Constructor

// Deconstructor
template <class T>
myArrays<T>::~myArrays(){
} // End of Deconstructor

template <class T>
void myArrays<T>:: myArraysBuilder(int rows, int cols){
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Builds the Arrays
    fillArrayOne();
    fillArrayTwo();
    fillArrayThree();
    
    // Prints the Arrays
    printArrayOne();
    printArrayTwo();
    printArrayThree();
    
    // Destroys the Arrays
    destroyOne();
    destroyTwo();
}

// fillArray func. #1
template <class T>
void myArrays<T>::fillArrayOne(){
    //Declare the 2-D Array
    array = new T*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new T[cols];
    }
    for(int row=0; row<rows;row++){
        for(int col=0;col<cols;col++){
            array[row][col]=rand()%90+10;
        }
    }
} // End of fillArray #1

// fillArray func. #2
template <class T>
void myArrays<T>::fillArrayTwo(){
    //Declare 1-D array
    colAry = new int[cols];
    //Fill the array with 2 digit numbers
    for(int col=0; col<cols;col++){
        colAry[col]=rand()%9+2;
    }
} // End of fillArray #2

// fillArray func. #3
template<class T>
void myArrays<T>::fillArrayThree(){
    // Declare the triArray
    triAry=new T*[rows];
    for(int row=0;row<rows;row++){
        triAry[row]=new T[colAry[row]];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            triAry[row][col]=((float)rand()/(float)(RAND_MAX)) * 100;
        }
    }
} // End of fillArray #3

// prrintArray #1
template <class T>
void myArrays<T>::printArrayOne(){
    cout<<"\n";
    cout<<"Print func. 1 (array) "<<"\n";
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<array[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
} // End of PrintArray #1

// printArray #2
template <class T>
void myArrays<T>:: printArrayTwo(){
    cout<<"\n";
    cout<<"Print func. 2 (colAry)"<<"\n";
    for(int col=0;col<cls;col++){
        cout<<colAry[col]<<" ";
        // *Note to self | Debug this part
        if(col%perLine==(perLine-1)){
            cout<<"\n";
        }
        cout<<"\n";
    }
} // End of printArray #2

// printArray #3
template <class T>
void myArrays<T>:: printArrayThree(){
    cout<<"\n";
    cout<<"Print func. 3 (triAry)"<<"\n";
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            cout<< setprecision(2) <<triAry[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
} // End of printArray #3

//  destroy func. #1
template<class T>
void myArrays<T>::destroyOne(){
    //Destroy array
    delete [] array;
} // End of destroy func. #1

// destroy func. #2
template<class T>
void myArrays<T>::destroyTwo(){
    // Delete triAry
    for(int row=0;row<rows;row++){
        delete [] triAry[row];
    }
    //Destroy colAry
    delete [] colAry;
} // End of destroy func. #2






