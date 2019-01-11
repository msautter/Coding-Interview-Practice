#pragma once
//Q1.4 Palindrome Permutation: Write a function to check if a string is a permutation of a palindrome

bool palPerm(char * oldString)
{
	if (sizeof(oldString) == 0)
		return false;

	size_t arraySize = sizeof(oldString) / sizeof(*oldString);
	//If even
	if (arraySize % 2 == 0)
	{
		sort(oldString, oldString + arraySize);
		for (int i = 0; i < arraySize; i++)
		{
			if (oldString[i] != oldString[i + 1])
			{
				return false;
			}
			i++;
		}
		return true;
	}
	//If its odd
	else
	{
		int halfwayPoint = (arraySize - 1) / 2;
		cout << halfwayPoint;
	}

}