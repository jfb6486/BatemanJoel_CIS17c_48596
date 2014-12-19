//
//  main.cpp
//  LnkdLst
//
//  Created by Joel Bateman on 09/24/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//

//System Libraries
#include <iostream>
#include <stdlib.h>

using namespace std;

//Our Library
#include "LnkdLst.h"

int main(int argc, char **argv)
{
    LinkedList<int> list;
    int data = 0;
    int referenceData = 0;
    int choice = 0;
    bool quit = false;
    
    cout << "\n\nThis is an INTEGER-based linked list!\n\n";
    
    do{
        cout << "\n1. Append data\n"
        << "2. Prepend data\n"
        << "3. Insert before element x\n"
        << "4. Insert after element x\n"
        << "5. Delete node from head\n"
        << "6. Delete node from tail\n"
        << "7. Delete a specific node\n"
        << "8. Show the list's data\n"
        << "0. Quit\n\n"
        << "     Select option: ";
        
        cin >> choice;
        
        switch (choice){
            case 1:
                cout<<"\nEnter data to add to the end of the list: ";
                cin>>data;
                list.append(data);
                break;
            case 2:
                cout<<"\nEnter data to add to the front of the list: ";
                cin>>data;
                list.prepend(data);
                break;
            case 3:
                cout<<"\nEnter reference data for new data to be placed before it: ";
                cin>>referenceData;
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
                quit = true;
                break;
            default:
                break;
        }
    } while (quit!=true);
    
    cout<<endl;
    
    return 0;
}