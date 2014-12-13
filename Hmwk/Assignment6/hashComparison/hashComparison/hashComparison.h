//
//  hashComparison.h
//  hashComparison
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __hashComparison__hashComparison__
#define __hashComparison__hashComparison__

#include <stdio.h>
#include <iostream>

using namespace std;

class hashComparison{

public:
    void compareHash();
    void Sort(char [], int);
    void LnSearch(char [], char [], int);
    void bnSearch(char [], char [], int, float);
    void Random(char [], int);
    
};

#endif /* defined(__hashComparison__hashComparison__) */
