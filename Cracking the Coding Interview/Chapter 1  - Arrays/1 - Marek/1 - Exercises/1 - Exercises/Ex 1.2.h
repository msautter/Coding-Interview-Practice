#pragma once
//While this method is the best with O(n), we can simplify this further below
bool checkPermutation(string text1, string text2)
{
	if (text1.length() != text2.length())
	{
		return false;
	}

	int charArray1[128] = { 0 };
	int charArray2[128] = { 0 };

	for (int i = 0; i < text1.length(); i++)
	{
		charArray1[(int)text1[i]]++;
		charArray2[(int)text2[i]]++;
	}

	for (int i = 0; i < 128; i++)
	{
		if (charArray1[i] != charArray2[i])
		{
			return false;
		}
	}
	return true;
}

//With this method, if we use quick sort, at worst case it could be O(n^2)
//but if we use merge sort then we will most likely get O(n log n)
bool checkPermutationSort(string text1, string text2)
{
	if (text1.length() != text2.length())
	{
		return false;
	}

	sort(text1.begin(), text1.end());
	sort(text2.begin(), text2.end());
	for (int i = 0; i < text1.length(); i++)
	{
		if (text1[i] != text2[i])
		{
			return false;
		}
	}
	return true;
}

bool checkPermutationCount(string text1, string text2)
{
	if (text1.length() != text2.length())
	{
		return false;
	}

	int charArray[128] = { 0 };

	for (int i = 0; i < text1.length(); i++)
	{
		charArray[(int)text1[i]]++;
		charArray[(int)text2[i]]--;
	}

	for (int i = 0; i < 128; i++)
	{
		if (charArray[i])
		{
			return false;
		}
	}
	return true;
}


//Extra material:
//https://www.geeksforgeeks.org/check-if-two-strings-are-permutation-of-each-other/