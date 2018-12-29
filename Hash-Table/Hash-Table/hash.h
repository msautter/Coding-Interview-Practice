#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#ifndef HASH_H
#define HASH_H

class HashClass 
{
private:
	//Creating a node that holds elements
	struct node {
		string name;
		int value;
		int sum;
		node * next;
	};

	//Array of nodes
	static const int tableSize = 10;
	node* HashTable[tableSize];
	const string emptyName = "[EMPTY]";

public:
	//Default Constructor
	HashClass();

	//Destructor 
	~HashClass();

	//Take string (key) and evaluate it into an int (index)
	int HashFunction(string key);

	//Take the name and number and add it to the hashTable
	void AddNode(string name, int value);

	//Take the index and find how many items are at that index
	int GetNumNodes(int index);

	//Print all the first items
	void PrintNodes();

	//Print all collisions at an index
	void PrintNodes(int index);

	//Return the value of a string
	int GetValue(string key);

	//Remove an entry from the hash table
	void RemoveNode(string key);
};

#endif // !HASH_H

