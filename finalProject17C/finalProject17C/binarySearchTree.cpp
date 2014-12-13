//
//  binarySearchTree.cpp
//  finalProject17C
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

#include "binarySearchTree.h"

#include <iostream>
#include "BST.H"
#include <string>

using namespace std;

binarySearchTree::binarySearchTree(){
    root = NULL;
}

// Function to create a new Node in heap
binarySearchTree::BstNode* BST::GetNewNode(std::string data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node
binarySearchTree::BstNode* BST::Insert(BstNode* root,std::string data) {
    if(root == NULL)// empty tree
        root = GetNewNode(data);
    
    // if data to be inserted is lesser, insert in left subtree.
    else if(data <= root->data)
        root->left = Insert(root->left,data);
    
    // else, insert in right subtree.
    else
        root->right = Insert(root->right,data);
    
    return root;
}

//To search an element in BST, returns true if element is found
bool binarySearchTree::Search(BstNode* root,std::string data) {
    if(root == NULL)
        return false;
    
    else if(root->data == data)
        return true;
    
    else if(data <= root->data)
        return Search(root->left,data);
    
    else
        return Search(root->right,data);
}
