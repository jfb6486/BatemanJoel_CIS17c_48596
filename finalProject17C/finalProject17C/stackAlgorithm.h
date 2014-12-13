//
//  stackAlgorithm.h
//  17CFinalComplete
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef ___7CFinalComplete__stackAlgorithm__
#define ___7CFinalComplete__stackAlgorithm__

#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class stackAlgorithm{
public:
    stackAlgorithm(){}
    ~stackAlgorithm(){}
    
    void execute();
    float h(float, stack<char>&);
    float g(float, stack<char>&);
    
};

#endif /* defined(___7CFinalComplete__stackAlgorithm__) */
