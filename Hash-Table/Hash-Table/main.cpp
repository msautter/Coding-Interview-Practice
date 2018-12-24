#include <iostream>
#include <string>
#include <cstdlib>

#include "hash.h"

using namespace std;

int main() {
	HashClass hashObj;

	//Adding names and values
	hashObj.AddItem("Marek", 763678);
	hashObj.AddItem("Sally", 235563);
	hashObj.AddItem("Joshi", 345123);
	hashObj.AddItem("Carla", 965674);
	hashObj.AddItem("Paula", 346732);
	hashObj.AddItem("Josef", 987896);
	hashObj.AddItem("Jesus", 292483);
	hashObj.AddItem("Nikko", 347258);
	hashObj.AddItem("Frank", 977345);
	hashObj.AddItem("David", 897634);

	//Printing values
	hashObj.PrintItems();
	system("PAUSE");
	return 0;
}
