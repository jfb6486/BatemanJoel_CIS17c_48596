#include <iostream>
#include <string>
#include <cstdlib>
#include<iomanip>
#include <cctype>
#include <stdlib.h>
#include <list>
#include <stack>
#include <map>


// Included Libraries
#include "Location.h"
#include "weightedGraph.h"
#include "dijkstraAlgorithm.h"

using namespace std;

// Allows to display or add data to a person continuously
void Menu(int currentLocation);
bool save = false;

int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 }, { 6, 8, 0, 0, 9 }, { 0, 5, 7, 9, 0 }, };
    
    bool active=true;
    
    while(active){
        cout<<"Select Current Location"<<endl;
        cout<<"   2    3"<<endl
        <<"(0)--(1)--(2)"<<endl
        <<" |   / \   |"<<endl
        <<"6| 8/   \5  |7"<<endl
        <<" | /     \ |"<<endl
        <<"(3)-------(4)"<<endl;
        cout<< "0 -> Home"<<endl;
        cout<< "1 -> Chevron"<<endl;
        cout<< "2 -> Vons"<<endl;
        cout<< "3 -> Wingstop"<<endl;
        cout<< "4 -> Winco"<<endl;
        cout<<"Location ID: ";
        int currentLocation;
        cin>>currentLocation;
        Menu(currentLocation);
        
        dijkstraAlgorithm d;
        cout<<"================================="<<endl<<
        "           START            "<<endl<<
        "================================="<<endl;
        weightedGraph w;
        w.primMST(graph);
        
        
        cout<<"================================="<<endl<<
        "       SHORTEST DISTANCE           "<<endl<<
        "================================="<<endl;
        // Shortest distance
        // graph is all values from problem plugged in
        // int represents the staring point and to trace
        // shortest distance of each point in the graph
        cout<<"Enter X (Starting Location)"<<endl;
        cout<<"ID"<<" "<<"  Location"<<endl;
        cout<< "0 -> Home"<<endl;
        cout<< "1 -> Chevron"<<endl;
        cout<< "2 -> Vons"<<endl;
        cout<< "3 -> Wingstop"<<endl;
        cout<< "4 -> Winco"<<endl;
        int location=0;
        cout<<"Location ID: ";
        cin>>location;
        switch(location){
            case 0:
                cout<<"   2    3"<<endl
                <<"(X)--(1)--(2)"<<endl
                <<" |   / \   |"<<endl
                <<"6| 8/   \5  |7"<<endl
                <<" | /     \ |"<<endl
                <<"(3)-------(4)"<<endl
                <<"      9"<<endl;
                break;
            case 1:
                cout<<"   2    3"<<endl
                <<"(0)--(X)--(2)"<<endl
                <<" |   / \   |"<<endl
                <<"6| 8/   \5  |7"<<endl
                <<" | /     \ |"<<endl
                <<"(3)-------(4)"<<endl
                <<"      9"<<endl;
                break;
            case 2:
                cout<<"   2    3"<<endl
                <<"(0)--(1)--(X)"<<endl
                <<" |   / \   |"<<endl
                <<"6| 8/   \5  |7"<<endl
                <<" | /     \ |"<<endl
                <<"(3)-------(4)"<<endl
                <<"      9"<<endl;
                break;
            case 3:
                cout<<"   2    3"<<endl
                <<"(0)--(1)--(2)"<<endl
                <<" |   / \   |"<<endl
                <<"6| 8/   \5  |7"<<endl
                <<" | /     \ |"<<endl
                <<"(X)-------(4)"<<endl
                <<"      9"<<endl;
                break;
            case 4:
                cout<<"   2    3"<<endl
                <<"(0)--(1)--(2)"<<endl
                <<" |   / \   |"<<endl
                <<"6| 8/   \5  |7"<<endl
                <<" | /     \ |"<<endl
                <<"(3)-------(X)"<<endl
                <<"      9"<<endl;
                break;
            default:
                cout<<"Invalid Entry";
                break;
        }
        d.dijkstra(graph, location);
        cout<<"Would you like to exit Distance"<<endl
        <<"Calculator?(y/n): ";
        char answer;
        cin>>answer;
        if(tolower(answer)=='y'){
            answer=false;
        }
        else{
            answer=true;
        }
    }
    // Exit stage right
    return 0;
}

void Menu(int currentLocation){
    bool quit = false;
    int choice = 0;
    InfoNode *infoNode;
    Location location;
    while(!quit){
        cout<<"================================="<<endl<<
        "             MENU            "<<endl<<
        "================================="<<endl;
        cout << "1) Add Stop\n"
        << "2) Delete Stop\n"
        << "3) View Stops\n"
        << "4) MST & Short Distance\n"
        << "5) Show Current Location\n"
        << "choice: ";
        cin  >> choice;
        switch(choice){
            case 1:
                int stopName;
                cin.ignore();
                cout<<"Select Location"<<endl;
                cout<<"   2    3"<<endl
                <<"(0)--(1)--(2)"<<endl
                <<" |   / \   |"<<endl
                <<"6| 8/   \5  |7"<<endl
                <<" | /     \ |"<<endl
                <<"(3)-------(4)"<<endl;
                cout<< "0 -> Home"<<endl;
                cout<< "1 -> Chevron"<<endl;
                cout<< "2 -> Vons"<<endl;
                cout<< "3 -> Wingstop"<<endl;
                cout<< "4 -> Winco"<<endl;
                cin>>stopName;
                location.addEntry(stopName);
                location.addNode(stopName, infoNode);
                save = false;
                break;
            case 2:
                location.deleteFirstStop();
                save = false;
                break;
            case 3:
                location.printStops();
                break;
            case 4:
                quit = true;
                break;
            case 5:
                cout<<"================================="<<endl<<
                "       CURRENT LOCATION            "<<endl<<
                "================================="<<endl;
                switch(currentLocation){
                    case 0:
                        cout<<"   2    3"<<endl
                        <<"(X)--(1)--(2)"<<endl
                        <<" |   / \   |"<<endl
                        <<"6| 8/   \5  |7"<<endl
                        <<" | /     \ |"<<endl
                        <<"(3)-------(4)"<<endl
                        <<"      9"<<endl;
                        break;
                    case 1:
                        cout<<"   2    3"<<endl
                        <<"(0)--(X)--(2)"<<endl
                        <<" |   / \   |"<<endl
                        <<"6| 8/   \5  |7"<<endl
                        <<" | /     \ |"<<endl
                        <<"(3)-------(4)"<<endl
                        <<"      9"<<endl;
                        break;
                    case 2:
                        cout<<"   2    3"<<endl
                        <<"(0)--(1)--(X)"<<endl
                        <<" |   / \   |"<<endl
                        <<"6| 8/   \5  |7"<<endl
                        <<" | /     \ |"<<endl
                        <<"(3)-------(4)"<<endl
                        <<"      9"<<endl;
                        break;
                    case 3:
                        cout<<"   2    3"<<endl
                        <<"(0)--(1)--(2)"<<endl
                        <<" |   / \   |"<<endl
                        <<"6| 8/   \5  |7"<<endl
                        <<" | /     \ |"<<endl
                        <<"(X)-------(4)"<<endl
                        <<"      9"<<endl;
                        break;
                    case 4:
                        cout<<"   2    3"<<endl
                        <<"(0)--(1)--(2)"<<endl
                        <<" |   / \   |"<<endl
                        <<"6| 8/   \5  |7"<<endl
                        <<" | /     \ |"<<endl
                        <<"(3)-------(X)"<<endl
                        <<"      9"<<endl;
                        break;
                    default:
                        cout<<"Invalid Entry";
                        break;
                }
                
                
        }
    }
}