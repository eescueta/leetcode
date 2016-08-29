#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
Examples:
s = "leetcode"
return 0.
s = "loveleetcode",
return 2.
*/

/*
"leetcode"
"loveleetcode"
*/

int firstUniqChar(string s) {
	map<char, int> charMap;

	for (int i = 0; i < s.length(); i++)
	{
		charMap[s[i]]++;
	}

	for (int j = 0; j < s.length(); j++)
	{
		if (charMap[s[j]] == 1)
			return j;
	}

	// no unique chararacters
	return -1;
}