//
//  main.cpp
//  SimpleVector
//
//  Created by Joel Bateman on 9/12/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main(int argc, char * argv[])
{
    SimpleVector<int> v(5);
    
    int next;
    
    cout<< "Enter "<<v.size()<<" elements into the vector.\n";
    cout<<"Input: ";
    
    for(unsigned int i=0;i<v.size();i++) {
        cin>>next;
        v[i]=next;
    }
    
    cout<<"\nThe elements you entered are.";
    for(int j=0;j<v.size();j++) {
        cout<<"\nElement "<<j+1<<") "<<v[j]<<" \n";
    }
    
    v.pushToTop(5);
    
    cout<<"\nThe elements you entered are.";
    for(int j=0;j<v.size();j++) {
        cout<<"\nElement "<<j+1<<") "<<v[j]<<" \n";
    }
    
    v.pullFromTop();
    
    cout<<"\nThe elements you entered are.";
    for(int j=0;j<v.size();j++) {
        cout<<"\nElement "<<j+1<<") "<<v[j]<<" \n";
    }
    
    return 0;
}

