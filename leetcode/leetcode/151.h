#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

void reverseWords(string &s) {
	// check if string is only spaces
	bool onlySpaces = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (!isspace(s[i]))
		{
			onlySpaces = false;
			break;
		}
	}

	if (onlySpaces)
	{ 
		s = "";
		return;
	}

	// get rid of spaces at the end
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			s.erase(s.begin() + i);
		}
		else
			break;
	}

	// remove extra spaces
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' '  && i < s.length() - 1 && s[i + 1] == ' ')
		{
			while (s[i + 1] == ' ')
			{
				s.erase(s.begin() + i + 1);

			}
		}
	}

	reverse(s.begin(), s.end());

	int it0 = 0;
	int it1 = 0;

	while (it0 < s.length())
	{
		if (it1 < s.length() && s[it1] != ' ')
			it1++;
		else
		{
			reverse(s.begin() + it0, s.begin() + it1);
			it0 = it1 + 1;
			it1++;
		}
	}

	// get rid of spaces at beginning


	// get rid of spaces at the end AGAIN
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			s.erase(s.begin() + i);
		}
		else
			break;
	}
}