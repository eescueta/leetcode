#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

/*
"abba"
"dog cat cat dog"
"abba"
"dog cat cat fish"
"aaaa"
"dog cat cat dog"
"abba"
"dog dog dog dog"
"ab"
"cat dog"
"ab"
"cat cat"
*/

bool wordPattern(string pattern, string str) {
	map<char, string> patternToStr;
	map<string, char> strToPattern;

	int pItr = 0;
	int strItr = 0;

	while (pItr < pattern.length() && strItr < str.length())
	{
		string currentWord = "";

		while (strItr < str.length() && str[strItr] != ' ')
		{
			currentWord += str[strItr];
			strItr++;
		}

		if (patternToStr[pattern[pItr]] != "")
		{
			if (patternToStr[pattern[pItr]] != currentWord)
				return false;
		}
		else if (strToPattern[currentWord]) // reverse check
		{
			if (strToPattern[currentWord] != pattern[pItr])
				return false;
		}
		else
		{
			patternToStr[pattern[pItr]] = currentWord;
			strToPattern[currentWord] = pattern[pItr];
		}

		strItr++;
		pItr++;
	}

	if (pItr < pattern.length() || strItr < str.length())
		return false;

	return true;
}