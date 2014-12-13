//
//  binarySearchTree.h
//  finalProject17C
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#ifndef __finalProject17C__binarySearchTree__
#define __finalProject17C__binarySearchTree__

#include <stdio.h>

using namespace std;
#include <iostream>

class binarySearchTree{
public:
    binarySearchTree();
    struct BstNode{
        string data;
        BstNode* left;
        BstNode* right;
    };
    
    BstNode* GetNewNode(std::string data);
    BstNode* Insert(BstNode* root,std::string data);
    bool Search(BstNode* root,std::string data);
    BstNode* root;
};
#endif /* defined(__finalProject17C__binarySearchTree__) */
