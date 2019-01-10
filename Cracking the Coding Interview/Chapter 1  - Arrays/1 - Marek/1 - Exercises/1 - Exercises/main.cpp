#include <iostream>
#include <algorithm>
using namespace std;

#include "Ex 1.1.h"
#include "Ex 1.2.h"
#include "Ex 1.3.h"
#include "Ex 1.4.h"
#include "Ex 1.5.h"
#include "Ex 1.6.h"
#include "Ex 1.7.h"
#include "Ex 1.8.h"
#include "Ex 1.9.h"


int main()
{
	cout << "Q 1.1: Implement an algorithm to determine if a string has all unique characters" << endl;
	cout << "Is the string \"Hello\" unique?: " << isUnique("Hello") << endl;
	cout << "Is the string \"World\" unique?: " << isUnique("World") << endl;
	cout << endl;

	cout << "Q 1.2: Given two string, write a method to decide if one is a permutation of the other" << endl;
	cout << "Is \"taco\" a permutation of \"cato\"?: " << checkPermutation("taco", "cato") << endl;
	cout << "Is \"hello\" a permutation of \"world\"?: " << checkPermutation("hello", "world") << endl;
	cout << endl;

	cout << "Q 1.3: Given a string, replace all spaces with %20" << endl;
	cout << "Input: Hello World, I am Ready! Output: ";
	char charArray[] = "Hello World, I am Ready!";
	cout << endl;

	cout << sizeof(charArray) << endl;
	urlifyNewString(charArray);
	
	cout << endl;

	system("PAUSE");
	return 0;
}