//
//  main.cpp
//  LinkedList
//
//  Created by Joel Bateman on 9/24/14.
//  Copyright (c) 2014 Joel Bateman. All rights reserved.
//

//System Libraries
#include <iostream>
#include <queue>
#include <list>

//Our Library
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv) {
    
    LinkedList<int> list;
    int data = 0;
    int referenceData = 0;
    int choice = 0;
    bool active = false;
    
    cout << "\n\nThis is an Integer only linked list!\n\n";
    
    do
    {
        // Options
        cout << "\n1. Append data "<<endl
        << "2. Prepend data"<<endl
        << "3. Insert before element x"<<endl
        << "4. Insert after element x"<<endl
        << "5. Remove node at the head"<<endl
        << "6. Remove node at the tail"<<endl
        << "7. Delete a specific node"<<endl
        << "8. Show the list's data"<<endl
        << "0. Quit"<<endl<<endl
        << "     Select option: ";
        
        // Input choice
        cin >> choice;
        
        
        switch (choice)
        {
            case 1:
                cout << "\nEnter data to add to the end of the list: ";
                cin >> data;
                list.append(data);
                break;
            case 2:
                cout << "\nEnter data to add to the front of the list: ";
                cin >> data;
                list.prepend(data);
                break;
            case 3:
                cout << "\nEnter reference data for new data to be placed before it: ";
                cin >> referenceData;
                cout << "\nNow please enter the new data: ";
                cin >> data;
                list.insertBefore(referenceData, data);
                break;
            case 4:
                cout << "\nEnter reference data for new data to be placed after it: ";
                cin >> referenceData;
                cout << "\nNow please enter the new data: ";
                cin >> data;
                list.insertAfter(referenceData, data);
                break;
            case 5:
                list.deleteFromHead();
                break;
            case 6:
                list.deleteFromTail();
                break;
            case 7:
                cout << "Enter data that is contained in an existing node,\nand I will remove that node from the list: ";
                cin >> data;
                list.deleteNode(data);
                break;
            case 8:
                cout << '\n';
                list.toString();
                break;
            case 0:
                active=false;
                break;
            default:
                break;
        }
    } while (active==true);
    
    cout << '\n';
    
    //Exit stage right!
    return 0;
}