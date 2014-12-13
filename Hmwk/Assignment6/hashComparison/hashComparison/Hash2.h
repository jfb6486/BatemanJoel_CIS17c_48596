#ifndef HASH2_H
#define HASH2_H
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std; 
// Index = buckets
class hshFun{
      private:
              static const int Table = 4;
              struct Item{
                    char name; 
                    Item *next;         
              };
              Item *hashTable; 
      public:
             // Default constructor
             hshFun();
             // Create the unique hash value for the name
             int Hash(char); 
             // Add an item to the list
             void addItem(char); 
             // Print the information
             void printTable(); 
             // Return drink
             void find(char);
};
#endif 
// Constructor
hshFun::hshFun(){
        hashTable = new Item; 
        hashTable->name = ' ';  
        hashTable->next = NULL; 
}
// A lot of stuff function
int hshFun::Hash(char key){
        int hash = 0;
        int ind;
        hash = (hash + (int)key) + 12;
        // Store remainder in the index
        ind = hash%Table; 
        return ind; 
}

// Add the item to the list
void hshFun::addItem(char n){
     int index = Hash(n); 
     if(hashTable->name == ' ')
         hashTable->name = n; 
     else{
          // Add new information 
          Item *nodePtr = hashTable; 
          Item *newNode = new Item;
          newNode->name = n; 
          newNode->next = NULL; 
          
          // Traverse the List
          while(nodePtr->next != NULL)
              nodePtr = nodePtr->next;
          // Link new Item to nodePtr
          nodePtr->next = newNode; 
     }
}
void hshFun::find(char n){
     int j = 0;
     // point to first item in index
     Item *nodePtr = hashTable; 
     // While nodePtr is pointing to some item
     while(nodePtr != NULL){
         if(nodePtr->name == n)
             break;
         nodePtr = nodePtr->next; 
     } 
}



