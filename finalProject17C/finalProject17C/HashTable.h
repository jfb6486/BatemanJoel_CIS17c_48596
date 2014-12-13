//
//  HashTable.h
//  finalProject17C
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//
#ifndef HASHTABLE
#define HASHTABLE

#include <list>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class HashTable
{
private:
	list<string> *table;
	int size;

public:
	HashTable(int size);
	~HashTable();

	void insert(string key);
	void find(string key);
	int getHashIndex(string key);
	void processFile(string filename);
	void printStats();
    void generateInitials(string, int, const int);
    
};
#endif