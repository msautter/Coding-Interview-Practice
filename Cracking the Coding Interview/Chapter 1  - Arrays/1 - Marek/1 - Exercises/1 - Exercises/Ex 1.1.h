#pragma once

//Q 1.1: Implement an algorithm to determine if a string has all unique characters
bool isUnique(string text)
{
	//Questions to ask:
		//May I assume we are using standard ASCII (128 possible values)?
		//Do we need to check if the string is empty?

	//If the string is greater than 128 then one char repeats
	if (text.length() > 128)
	{
		cout << "Too long!" << endl;
		return false;
	}

	//Create a boolean array to determine and initialize all values to false
	bool boolArray[128];
	for (int i = 0; i < 128; i++)
	{
		boolArray[i] = false;
	}

	//Loop through the string to mark used characters
	for (int i = 0; i < text.length(); i++)
	{
		//Check to see if the value has already been marked and return false if not unique
		if (boolArray[(int)text[i]])
		{
			return false;
		}
		//Mark the character as being used
		boolArray[(int)text[i]] = true;
	}
	return true;
}


//Extra material:
//https://www.geeksforgeeks.org/determine-string-unique-characters/


//Q 1.1.2: What if you cannot use additional data structures?
