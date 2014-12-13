//
//  HashTable.cpp
//  finalProject17C
//
//  Created by Joel Bateman on 12/12/14.
//  Copyright (c) 2014 Alpha. All rights reserved.
//
#include "HashTable.h"

HashTable::HashTable(int size)
{
	this->size = size;
	table = new list<string>[size];
}

HashTable::~HashTable()
{
	delete[] table;
	table = NULL;
}

void HashTable::insert(string key)
{
	int hashIndex = getHashIndex(key);
	table[hashIndex].push_back(key);
}

void HashTable::find(string key)
{
	int hashIndex = 0;
	
	if (key.at(0) == 'A' || key.at(0) == 'B' || key.at(0) == 'C')
		hashIndex = hashIndex + 2 * 100;
	else if (key.at(0) == 'D' || key.at(0) == 'E' || key.at(0) == 'F')
		hashIndex = hashIndex + 3 * 100;
	else if (key.at(0) == 'G' || key.at(0) == 'H' || key.at(0) == 'I')
		hashIndex = hashIndex + 4 * 100;
	else if (key.at(0) == 'J' || key.at(0) == 'K' || key.at(0) == 'L')
		hashIndex = hashIndex + 5 * 100;
	else if (key.at(0) == 'M' || key.at(0) == 'N' || key.at(0) == 'O')
		hashIndex = hashIndex + 6 * 100;
	else if (key.at(0) == 'P' || key.at(0) == 'Q' || key.at(0) == 'R' || key.at(0) == 'S')
		hashIndex = hashIndex + 7 * 100;
	else if (key.at(0) == 'T' || key.at(0) == 'U' || key.at(0) == 'V')
		hashIndex = hashIndex + 8 * 100;
	else if (key.at(0) == 'W' || key.at(0) == 'X' || key.at(0) == 'Y' || key.at(0) == 'Z')
		hashIndex = hashIndex + 9 * 100;

	if (key.at(1) == 'A' || key.at(1) == 'B' || key.at(1) == 'C')
		hashIndex = hashIndex + 2 * 10;
	else if (key.at(1) == 'D' || key.at(1) == 'E' || key.at(1) == 'F')
		hashIndex = hashIndex + 3 * 10;
	else if (key.at(1) == 'G' || key.at(1) == 'H' || key.at(1) == 'I')
		hashIndex = hashIndex + 4 * 10;
	else if (key.at(1) == 'J' || key.at(1) == 'K' || key.at(1) == 'L')
		hashIndex = hashIndex + 5 * 10;
	else if (key.at(1) == 'M' || key.at(1) == 'N' || key.at(1) == 'O')
		hashIndex = hashIndex + 6 * 10;
	else if (key.at(1) == 'P' || key.at(1) == 'Q' || key.at(1) == 'R' || key.at(1) == 'S')
		hashIndex = hashIndex + 7 * 10;
	else if (key.at(1) == 'T' || key.at(1) == 'U' || key.at(1) == 'V')
		hashIndex = hashIndex + 8 * 10;
	else if (key.at(1) == 'W' || key.at(1) == 'X' || key.at(1) == 'Y' || key.at(1) == 'Z')
		hashIndex = hashIndex + 9 * 10;

	if (key.at(2) == 'A' || key.at(2) == 'B' || key.at(2) == 'C')
		hashIndex = hashIndex + 2;
	else if (key.at(2) == 'D' || key.at(2) == 'E' || key.at(2) == 'F')
		hashIndex = hashIndex + 3;
	else if (key.at(2) == 'G' || key.at(2) == 'H' || key.at(2) == 'I')
		hashIndex = hashIndex + 4;
	else if (key.at(2) == 'J' || key.at(2) == 'K' || key.at(2) == 'L')
		hashIndex = hashIndex + 5;
	else if (key.at(2) == 'M' || key.at(2) == 'N' || key.at(2) == 'O')
		hashIndex = hashIndex + 6;
	else if (key.at(2) == 'P' || key.at(2) == 'Q' || key.at(2) == 'R' || key.at(2) == 'S')
		hashIndex = hashIndex + 7;
	else if (key.at(2) == 'T' || key.at(2) == 'U' || key.at(2) == 'V')
		hashIndex = hashIndex + 8;
	else if (key.at(2) == 'W' || key.at(2) == 'X' || key.at(2) == 'Y' || key.at(2) == 'Z')
		hashIndex = hashIndex + 9;


	if (hashIndex >= 111 && hashIndex <= 999)
	{
		if (table[hashIndex].size() == 0)
		{
			//cout << "Initials not found\n\n";
		}
		else
			for (list<string>::iterator it = table[hashIndex].begin(); it != table[hashIndex].end(); it++)
				if (*it == key)
				{
					continue;
					//cout << "Initials found at table[" << hashIndex << "]\n";
				}
		//cout << '\n';
	}
	else
		cout << "Initials not found\n\n";

	
}

int HashTable::getHashIndex(string key)
{
	int hashIndex = 0;
	
	if (key.at(0) == 'A' || key.at(0) == 'B' || key.at(0) == 'C')
		hashIndex = hashIndex + 2 * 100;
	else if (key.at(0) == 'D' || key.at(0) == 'E' || key.at(0) == 'F')
		hashIndex = hashIndex + 3 * 100;
	else if (key.at(0) == 'G' || key.at(0) == 'H' || key.at(0) == 'I')
		hashIndex = hashIndex + 4 * 100;
	else if (key.at(0) == 'J' || key.at(0) == 'K' || key.at(0) == 'L')
		hashIndex = hashIndex + 5 * 100;
	else if (key.at(0) == 'M' || key.at(0) == 'N' || key.at(0) == 'O')
		hashIndex = hashIndex + 6 * 100;
	else if (key.at(0) == 'P' || key.at(0) == 'Q' || key.at(0) == 'R' || key.at(0) == 'S')
		hashIndex = hashIndex + 7 * 100;
	else if (key.at(0) == 'T' || key.at(0) == 'U' || key.at(0) == 'V')
		hashIndex = hashIndex + 8 * 100;
	else if (key.at(0) == 'W' || key.at(0) == 'X' || key.at(0) == 'Y' || key.at(0) == 'Z')
		hashIndex = hashIndex + 9 * 100;

	if (key.at(1) == 'A' || key.at(1) == 'B' || key.at(1) == 'C')
		hashIndex = hashIndex + 2 * 10;
	else if (key.at(1) == 'D' || key.at(1) == 'E' || key.at(1) == 'F')
		hashIndex = hashIndex + 3 * 10;
	else if (key.at(1) == 'G' || key.at(1) == 'H' || key.at(1) == 'I')
		hashIndex = hashIndex + 4 * 10;
	else if (key.at(1) == 'J' || key.at(1) == 'K' || key.at(1) == 'L')
		hashIndex = hashIndex + 5 * 10;
	else if (key.at(1) == 'M' || key.at(1) == 'N' || key.at(1) == 'O')
		hashIndex = hashIndex + 6 * 10;
	else if (key.at(1) == 'P' || key.at(1) == 'Q' || key.at(1) == 'R' || key.at(1) == 'S')
		hashIndex = hashIndex + 7 * 10;
	else if (key.at(1) == 'T' || key.at(1) == 'U' || key.at(1) == 'V')
		hashIndex = hashIndex + 8 * 10;
	else if (key.at(1) == 'W' || key.at(1) == 'X' || key.at(1) == 'Y' || key.at(1) == 'Z')
		hashIndex = hashIndex + 9 * 10;

	if (key.at(2) == 'A' || key.at(2) == 'B' || key.at(2) == 'C')
		hashIndex = hashIndex + 2;
	else if (key.at(2) == 'D' || key.at(2) == 'E' || key.at(2) == 'F')
		hashIndex = hashIndex + 3;
	else if (key.at(2) == 'G' || key.at(2) == 'H' || key.at(2) == 'I')
		hashIndex = hashIndex + 4;
	else if (key.at(2) == 'J' || key.at(2) == 'K' || key.at(2) == 'L')
		hashIndex = hashIndex + 5;
	else if (key.at(2) == 'M' || key.at(2) == 'N' || key.at(2) == 'O')
		hashIndex = hashIndex + 6;
	else if (key.at(2) == 'P' || key.at(2) == 'Q' || key.at(2) == 'R' || key.at(2) == 'S')
		hashIndex = hashIndex + 7;
	else if (key.at(2) == 'T' || key.at(2) == 'U' || key.at(2) == 'V')
		hashIndex = hashIndex + 8;
	else if (key.at(2) == 'W' || key.at(2) == 'X' || key.at(2) == 'Y' || key.at(2) == 'Z')
		hashIndex = hashIndex + 9;
		

	return hashIndex;
}

void HashTable::processFile(string filename)
{
	ifstream myfile(filename);
	string line = "\0";

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			insert(line);
		}

		myfile.close();
	}

	else cout << "Unable to open file\n\n";
}

void HashTable::printStats()
{
    int numOfCollisions = 0;
    int longestChain = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (table[i].size() > 1)
            numOfCollisions += table[i].size() - 1;
        
        if (table[i]. size() > longestChain)
            longestChain = table[i].size();
    }
    
    std::cout << "Size of table: " << size << '\n';
    std::cout << "Number of collisions: " << numOfCollisions << '\n';
    std::cout << "Longest chain: " << longestChain << "\n\n";
}

void HashTable::generateInitials(string file, int numOfInitials, int const SIZE)
{
    srand((unsigned int)time(0));
    ofstream outFile(file);
    
    string *initials = new string[SIZE];
    
    // Create an array of random 3-letter initials
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < numOfInitials; j++)
        {
            char mChar = 'A' + rand() % 26;
            initials[i] += mChar;
        }
    }
    
    if (outFile.is_open())
    {
        // Print array of random 3-letter initials
        for (int i = 0; i < SIZE; i++)
        {
            outFile << initials[i] << '\n';
        }
        
        outFile.close();
    }
    else{
        cout << "Unable to open file\n\n";
    }
}