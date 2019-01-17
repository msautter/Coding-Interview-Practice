#pragma once
//Q1.4 Palindrome Permutation: Write a function to check if a string is a permutation of a palindrome

bool palPerm(string givenString)
{
	int charArray[256] = { 0 };


	//Get a count of all the letters
	for (int i = 0; givenString[i]; i++)
	{
		charArray[givenString[i]]++;
	}


	//We can only have one number that is odd
	int odd = 0;

	for (int i = 0; i < 256; i++)
	{
		//If the value is odd then we 
		if (charArray[i] % 2)
			odd++;

		if (odd > 1)
			return false;
	}
	return true;
}