#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include "Solution.h"

using namespace std;

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

/*
"babad"
"cbbd"
"dksjafhdsaljkhfabbaccsdjf"
"ccc"
*/

string longestPalindrome(string s) {
	vector<vector<bool> > isAnagram(s.length(), vector<bool>(s.length(), false));

	int curMaxLength = 0;
	string currLongestPalindrome = "";

	// all characters of one length are considered palindromes
	for (int i = 0; i < isAnagram.size(); i++)
	{
		isAnagram[i][i] = true;
		if (curMaxLength < 1)
		{
			curMaxLength = 1;
			currLongestPalindrome = s[i];
		}

		if (i != isAnagram.size() - 1)
		{
			if (s[i] == s[i + 1])
			{
				isAnagram[i][i + 1] = true;
				if (curMaxLength != 2)
				{
					curMaxLength = 2;
					currLongestPalindrome = s.substr(i, 2);
				}
			}
		}
	}

	// mark all palindromes of length two
	//for (int i = 0; i < isAnagram.size() - 1; i++)
	//{
	//	if (s[i] == s[i + 1])
	//	{
	//		isAnagram[i][i + 1] = true;
	//		if (curMaxLength != 2)
	//		{
	//			curMaxLength = 2;
	//			currLongestPalindrome = s.substr(i, 2);
	//		}
	//	}
	//}
	
	// palindromes of length three and more
	for (int i = 3; i <= isAnagram.size(); i++)
	{
		for (int k = 0; k < isAnagram.size() - (i-1); k++)
		{
			if (s[k] == s[k + i - 1] && isAnagram[k + 1][k + i - 2])
			{
				isAnagram[k][k + i - 1] = true;
				if (i > curMaxLength)
				{
					curMaxLength = i;
					currLongestPalindrome = s.substr(k, i);
				}
			}
		}
	}
	return currLongestPalindrome;
}