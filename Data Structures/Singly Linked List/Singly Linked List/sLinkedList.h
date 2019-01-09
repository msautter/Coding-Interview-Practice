#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

class SSLClass
{
private:
	typedef struct node {
		int value;
		node * next;
	} * nodePtr;

	nodePtr headPtr;
	nodePtr tempPtr1;
	nodePtr tempPtr2;
	
public:

	//Default constructor
	SSLClass();

	//Add a value to the linked list
	void AddNode(int value);

	//Add a value at an index
	void AddIndex(int index, int value);

	//Remove a value from the linked list
	void RemoveNode(int value);

	//Prints the list
	void PrintList();

	//Gets the length of the SSL
	int GetLength();

	//Remove at index
	void RemoveIndex(int index);

	~SSLClass();
};

#endif SLINKEDLIST_H