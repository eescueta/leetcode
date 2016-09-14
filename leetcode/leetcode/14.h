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
Write a function to find the longest common prefix string amongst an array of strings.
*/

/*
["arturo", "arthur", "arteezy"]
["abc", "def", "efg"]
[]

*/

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() <= 0)
		return "";

	//find smallest string
	int smallestLength = INT_MAX;
	for (int i = 0; i < strs.size(); i++)
	{
		if (strs[i].length() < smallestLength)
			smallestLength = strs[i].length();
	}

	string result = "";
	for (int i = 0; i < smallestLength; i++)
	{
		char currChar = strs[0][i];
		bool match = true;
		for (int j = 1; j < strs.size(); j++)
		{
			if (strs[j][i] != currChar)
			{
				match = false;
				break;
			}
		}
		if (match)
			result += currChar;
		else
			return result;
	}

	return result;
}