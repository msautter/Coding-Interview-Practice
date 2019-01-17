#pragma once

//Q1.3 Write a method to replace all spaces in a string with %20

//A simple solution would be to create a second string and copy characters in one by one. Whenever a space is encountered replace it with %20

void urlifyNewString(char * oldString)
{
	int numSpaces = 0;

	for (int i = 0; i < strlen(oldString); i++)
	{
		if (oldString[i] == ' ')
		{
			numSpaces++;
		}
	}
	cout << "Number of spaces is: " << numSpaces << endl;
	cout << "Old string size is: " << strlen(oldString) << endl;
	int newStringSize = strlen(oldString) + numSpaces * 2;
	cout << "The new string length is: " << newStringSize << endl;

	char * newString = new char[strlen(oldString) + numSpaces * 2];

	int j = 0;
	for (int i = 0; i < strlen(oldString); i++)
	{
		if (oldString[i] == ' ')
		{
			newString[j] = '%';
			j++;
			newString[j] = '2';
			j++;
			newString[j] = '0';
		}
		else
		{
			newString[j] = oldString[i];
		}
		j++;
	}
	cout << newString;
	cout << endl;
}



//Additonal information: https://www.geeksforgeeks.org/urlify-given-string-replace-spaces/