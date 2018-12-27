#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "hash.h"
using namespace std;

int main() {
	HashClass hashObj;

	//Adding names and values
	hashObj.AddNode("--00--", 100000);
	hashObj.AddNode("--01--", 100001);
	hashObj.AddNode("--02--", 100010);
	hashObj.AddNode("--03--", 100011);
	hashObj.AddNode("--04--", 100100);
	hashObj.AddNode("--05--", 100101);
	hashObj.AddNode("--06--", 100110);
	hashObj.AddNode("--07--", 100111);
	hashObj.AddNode("--08--", 101000);
	hashObj.AddNode("--09--", 101001);
	hashObj.AddNode("--10--", 101010);
	hashObj.AddNode("--11--", 101011);
	hashObj.AddNode("--12--", 101100);
	hashObj.AddNode("--13--", 101101);
	hashObj.AddNode("--14--", 101110);
	hashObj.AddNode("--15--", 101111);
	hashObj.AddNode("--16--", 110000);
	hashObj.AddNode("--17--", 110001);
	hashObj.AddNode("--18--", 110010);
	hashObj.AddNode("--19--", 110011);

	cout << ">-Printing Table..." << endl;
	hashObj.PrintNodes();
	cout << endl;

	cout << ">-Printing a row..." << endl;
	hashObj.PrintNodes(2);
	cout << endl;

	cout << ">-Deleting a node..." << endl;
	hashObj.RemoveNode("Nine");
	cout << endl;

	cout << ">-Deleting a node again..." << endl;
	hashObj.RemoveNode("--09--");
	cout << endl;

	cout << ">-Printing Table..." << endl;
	hashObj.PrintNodes();
	cout << endl;

	cout << ">-Deleting Table..." << endl;
	hashObj.~HashClass();

	system("PAUSE");
	return 0;
}
