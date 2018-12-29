#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "sLinkedList.h"
using namespace std;

int main()
{
	SSLClass sslObj;

	cout << ">- Adding values 5 to the front";
	sslObj.AddIndex(0, 5);
	cout << endl;

	cout << ">- printing list...\n";
	sslObj.PrintList();
	cout << endl;

	cout << ">- Getting list length...\n";
	printf("   List Length: (%d)\n", sslObj.GetLength());
	cout << endl;

	//cout << ">- Deleting 9...\n";
	//sslObj.RemoveNode(9);
	//cout << endl;

	//cout << ">- Printing list...\n";
	//sslObj.PrintList();
	//cout << endl;

	//cout << ">- Removing index 1...\n";
	//sslObj.RemoveIndex(1);
	//cout << endl;

	//cout << ">- Printing list...\n";
	//sslObj.PrintList();
	//cout << endl;

	//cout << ">- Adding values 15, 10, and 5...\n";
	//sslObj.AddNode(15);
	//sslObj.AddNode(10);
	//sslObj.AddNode(5);
	//cout << endl;

	//cout << ">- Printing list...\n";
	//sslObj.PrintList();
	//cout << endl;

	//cout << ">- Adding 99 to index 2 list...\n";
	//sslObj.AddIndex(2, 99);
	//cout << endl;

	//cout << ">- Printing list...\n";
	//sslObj.PrintList();
	//cout << endl;

	//cout << ">- Deleting list...\n";
	//sslObj.~SSLClass();
	//cout << endl;

	system("PAUSE");
	return 0;
}