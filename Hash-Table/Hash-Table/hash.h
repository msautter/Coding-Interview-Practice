#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

#ifndef HASH_H
#define HASH_H

class HashClass 
{
private:
	const string emptyName = "[EMPTY]";
	//Setting the arraySize to be 10
	static const int tableSize = 100;

	//Creating a hashNode that holds elements
	struct HashNode {
		string name;
		int value;
		HashNode * next;
	};

	HashNode* HashTable[tableSize];
public:
	//hashClass constructor
	HashClass();

	//Take string (key) and evaluate it into an int (index)
	int Hash(string key);

	//Take the name and number and add it to the hashTable
	void AddItem(string name, int value);

	//Take the index and find how many items are at that index
	int GetNumItems(int index);

	//Print all elements at an index
	void PrintItems();
};

#endif // !HASH_H

