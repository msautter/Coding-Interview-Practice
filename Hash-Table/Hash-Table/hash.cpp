#include <iostream>
#include <string>
#include <cstdlib>
#include "hash.h"

using namespace std;

HashClass::HashClass()
{
	for (int i = 0; i < tableSize; i++)
	{
		//Set initial values for each attribute
		HashTable[i] = new HashNode;
		HashTable[i]->name = emptyName;
		HashTable[i]->value = 0;
		HashTable[i]->next = NULL;
	}
}

void HashClass::AddItem(string name, int value)
{
	//Get the index by hashing the name
	int index = Hash(name);
	//Check to see if the list is empty at the index and assign the object if it is
	if (HashTable[index]->name == emptyName)
	{
		HashTable[index]->name = name;
		HashTable[index]->value = value;
	}
	else
	{
		//Since there already exists a node, create a newNode to add to the end
		HashNode * newNode = new HashNode;
		newNode->name = name;
		newNode->value = value;
		newNode->next = NULL;

		//Loop to get to the end of the list
		HashNode * tempPtr = HashTable[index];
		while (tempPtr->next != NULL) { tempPtr = tempPtr->next; }

		//Add our new node to the end of the list
		tempPtr->next = newNode;
	}
}

int HashClass::GetNumItems(int index)
{
	//Creating initial count to be incremented
	int count = 0;
	//If the first index is empty return zero
	if (HashTable[index]->name == emptyName) { return count; }
	else
	{
		//Keep counting until we reach the end, then return count
		count++;
		HashNode * tempPtr = HashTable[index];
		while (tempPtr->next != NULL) 
		{ 
			count++;
			tempPtr = tempPtr->next; 
			
		}
	}
	return count;
}

void HashClass::PrintItems()
{	
	//Simple print function that prints the first value of the hash table
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = GetNumItems(i);
		cout << "[" << i << "] (" << number << ") : Name: " << HashTable[i]->name << ", value: " << HashTable[i]->value << endl;
	}
}
int HashClass::Hash(string key)
{
	//Hash function for determining the index given the string
	int index;
	int sum = 0;
	for (int i = 0; i < key.length(); i++) { sum += (int)key[i]; }
	index = sum % tableSize;

	return index;
}