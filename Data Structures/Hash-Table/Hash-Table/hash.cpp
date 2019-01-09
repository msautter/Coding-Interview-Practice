#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "hash.h"
using namespace std;

//Sets up the array with default nodes
HashClass::HashClass()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new node;
		HashTable[i]->name = emptyName;
		HashTable[i]->value = 0;
		HashTable[i]->sum = 0;
		HashTable[i]->next = NULL;
	}
}

HashClass::~HashClass()
{
	node* delNode;
	for (int i = 0; i < tableSize; i++)
	{
		while (HashTable[i] != NULL)
		{
			
			delNode = HashTable[i];
			HashTable[i] = HashTable[i]->next;
			delete delNode;
		}
		cout << "[" << setw(2) << i << "] (0) : | SUCCESS: ROW DELETED" << endl;
	}
}

//Return the value of a string
int HashClass::GetValue(string key)
{
	int index = HashFunction(key);
	int numNodes = GetNumNodes(index);
	node * tempNode = HashTable[index];
	while (tempNode != NULL)
	{
		if (tempNode->name == key)
		{
			return tempNode->value;
		}
		tempNode = tempNode->next;
	}
	cout << "[" << setw(2) << index << "] (" << numNodes << ") : | ERROR - \"" << key << "\" NOT FOUND" << endl;
	return 0;
}

//Return the index of a hashed string
int HashClass::HashFunction(string key)
{
	int index = 0;
	for (int i = 0; i < key.length(); i++) 
	{ 
		index += ((int)key[i]) * 1; 
	}
	return index % tableSize;
}

//ADD A NAME AND VALUE TO THE HASH TABLE
void HashClass::AddNode(string key, int value)
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++)
	{
		sum += (int)key[i];
	}

	int index = HashFunction(key);
	if (HashTable[index]->name == emptyName)
	{
		HashTable[index]->name = key;
		HashTable[index]->sum = sum;
		HashTable[index]->value = value;
	}
	else
	{
		node * newNode = new node;
		newNode->name = key;
		newNode->value = value;
		newNode->sum = sum;
		newNode->next = NULL;

		node * tempNode = HashTable[index];
		while (tempNode->next != NULL) 
		{ 
			tempNode = tempNode->next; 
		}
		tempNode->next = newNode;
	}
}

//Return the number of items
int HashClass::GetNumNodes(int index)
{
	int count = 0;
	if (HashTable[index]->name == emptyName) 
	{ 
		return count; 
	}
	else
	{
		count++;
		node * tempNode = HashTable[index];
		while (tempNode->next != NULL) 
		{ 
			count++;
			tempNode = tempNode->next; 
		}
	}
	return count;
}
//Print the entire HashTable
void HashClass::PrintNodes()
{	
	int numNodes;
	cout << "------------ HASH TABLE (" << tableSize << ") ------------" << endl;
	for (int i = 0; i < tableSize; i++)
	{
		numNodes = GetNumNodes(i);
		if (numNodes == 0)
		{
			cout << "[" << setw(2) << i << "] (" << numNodes << ") : | ";
		}
		else
		{
			cout << "[" << setw(2) << i << "] (" << numNodes << ") : | {N: " << HashTable[i]->name << ", V: " << HashTable[i]->value << ", S: " << HashTable[i]->sum << "} ";
			if (HashTable[i]->next != NULL)
			{
				node * tempNode = HashTable[i]->next;
				while (tempNode != NULL)
				{
					cout << "{N: " << tempNode->name << ", V: " << tempNode->value << ", S: " << tempNode->sum << "} ";
					tempNode = tempNode->next;
				}
			}
		}
		cout << endl;
	}
	cout << "------------ HASH TABLE (" << tableSize << ") ------------" << endl;
}

//Print the HashTable at an index
void HashClass::PrintNodes(int index)
{
	int numNodes = GetNumNodes(index);
	if (numNodes == 0)
	{
		cout << "[" << setw(2) << index << "] (" << numNodes << ") : | ";
	}
	else
	{
		cout << "[" << setw(2) << index << "] (" << numNodes << ") : | {N: " << HashTable[index]->name << ", V: " << HashTable[index]->value << "} ";
		if (HashTable[index]->next != NULL)
		{
			node * tempNode = HashTable[index]->next;
			while (tempNode != NULL)
			{
				cout << "{N: " << tempNode->name << ", V: " << tempNode->value << "} ";
				tempNode = tempNode->next;
			}
		}
	}
	cout << endl;
}

void HashClass::RemoveNode(string key)
{
	int index = HashFunction(key);
	int numNodes = GetNumNodes(index);
	
	switch (numNodes)
	{
		//If the key is the first and only node
	case 1:
		if (HashTable[index]->name == key)
		{
			HashTable[index]->name = emptyName;
			HashTable[index]->value = 0;
			cout << "[" << setw(2) << index << "] (" << numNodes << ") : | SUCCESS - \"" << key << "\" WAS REMOVED" << endl;
			break;
		}
		// If there are no nodes
	case 0:
		cout << "[" << setw(2) << index << "] (" << numNodes << ") : | ERROR - \"" << key << "\" NOT FOUND" << endl;
		break;
	default:
		// If the first is the node in a list of nodes
		if (HashTable[index]->name == key)
		{
			node * delNode = HashTable[index];
			HashTable[index] = HashTable[index]->next;
			delete delNode;
			cout << "[" << setw(2) << index << "] (" << numNodes << ") : | SUCCESS - \"" << key << "\" WAS REMOVED" << endl;
		}
		// If the node is after the first
		else
		{
			node * tempPtr1 = HashTable[index];
			node * tempPtr2 = HashTable[index]->next;

			while (tempPtr2 != NULL && tempPtr2->name != key)
			{
				tempPtr1 = tempPtr2;
				tempPtr2 = tempPtr2->next;
			}
			if (tempPtr2 == NULL)
			{
				cout << "[" << setw(2) << index << "] (" << numNodes << ") : | ERROR - \"" << key << "\" NOT FOUND" << endl;
			}
			else
			{
				node * delNode = tempPtr2;
				tempPtr2 = tempPtr2->next;
				tempPtr1->next = tempPtr2;
				delete delNode;
				cout << "[" << setw(2) << index << "] (" << numNodes << ") : | SUCCESS - \"" << key << "\" WAS REMOVED" << endl;
			}
		}
	}
}