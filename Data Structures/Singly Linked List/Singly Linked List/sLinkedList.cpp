#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "sLinkedList.h"
using namespace std;


SSLClass::SSLClass()
{
	headPtr = NULL;
	tempPtr1 = NULL;
	tempPtr2 = NULL;
}

// Adding a node to the back of the list
void SSLClass::AddNode(int value)
{
	nodePtr newNode = new node;
	newNode->next = NULL;
	newNode->value = value;

	if (headPtr == NULL)
	{
		headPtr = newNode;
	}
	else
	{
		tempPtr1 = headPtr;
		while (tempPtr1->next != NULL)
		{
			tempPtr1 = tempPtr1->next;
		}
		tempPtr1->next = newNode;
	}
}

// Add a value at an index
void SSLClass::AddIndex(int index, int value)
{
	int count = 0;
	if (GetLength() - 1 < index && GetLength() != 0)
	{
		cout << "   ERROR: Index out of range" << endl;
	}
	else if (GetLength() == 0)
	{
		cout << "Hello";
		AddNode(value);
	}
	else
	{
		tempPtr1 = headPtr;
		tempPtr2 = headPtr;

		while (tempPtr2 != NULL && index != count)
		{
			tempPtr1 = tempPtr2;
			tempPtr2 = tempPtr2->next;
			count++;
		}
		nodePtr newNode = new node;
		newNode->next = tempPtr2;
		newNode->value = value;
		tempPtr1->next = newNode;
	}
}

// Search through the list and remove the first instance of a value
void SSLClass::RemoveNode(int value)
{
	tempPtr1 = headPtr;
	tempPtr2 = headPtr;
	while (tempPtr2 != NULL && tempPtr2->value != value)
	{
		tempPtr1 = tempPtr2;
		tempPtr2 = tempPtr2->next;
	}
	if (tempPtr2 == NULL)
	{
		cout << "   ERROR: Value NOT FOUND" << endl;
	}
	else
	{
		nodePtr delPtr = tempPtr2;
		tempPtr2 = tempPtr2->next;
		tempPtr1->next = tempPtr2;
		if (delPtr == headPtr)
		{
			headPtr = headPtr->next;
			tempPtr1 = NULL;
		}
		delete delPtr;
		printf("   %d was found and deleted!\n", value);
	}
}

// Remove a value at an index
void SSLClass::RemoveIndex(int index)
{
	int count = 0;
	if (GetLength() - 1 < index)
	{
		cout << "   ERROR: Index out of range" << endl;
	}
	else
	{
		tempPtr1 = headPtr;
		tempPtr2 = headPtr;

		while (tempPtr2 != NULL && index != count)
		{
			tempPtr1 = tempPtr2;
			tempPtr2 = tempPtr2->next;
			count++;
		}
		nodePtr delPtr = tempPtr2;
		tempPtr2 = tempPtr2->next;
		tempPtr1->next = tempPtr2;
		if (delPtr == headPtr)
		{
			headPtr = headPtr->next;
			tempPtr1 = NULL;
		}
	}
	
}

// Loop through the list to see how long it is
int SSLClass::GetLength()
{
	int count = 0;
	if (headPtr == NULL)
	{
		return count;
	}
	else
	{
		count++;
		tempPtr1 = headPtr;
		while (tempPtr1->next != NULL)
		{
			count++;
			tempPtr1 = tempPtr1->next;
		}
	}
	return count;
}

// Just print the list
void SSLClass::PrintList()
{
	string message;
	int count = 0;
	tempPtr1 = headPtr;
	while (tempPtr1 != NULL)
	{
		printf("   {  (%d)  }  ", tempPtr1->value);
		if (tempPtr1->next != NULL)
		{
			cout << "-->";
		}
		count++;
		tempPtr1 = tempPtr1->next;
	}
	cout << endl;
}

// Delete everything
SSLClass::~SSLClass()
{
	nodePtr delPtr = headPtr;
	while (headPtr != NULL)
	{
		delPtr = headPtr;
		headPtr = headPtr->next;
		delete delPtr;
	}
}
