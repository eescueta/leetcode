#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

/*
""
""
"sad"
"sa"
"sad"
"saf"
"sa"
"daf"
"teacher"
"detacher"
"teacher"
"etacher"
*/

bool isOneEditDistance(string s, string t) {
	if (s == t) return false;
	if (s.length() < t.length()) swap(s, t);
	if (s.length() - t.length() > 1) return false;

	if (s.length() == t.length())
	{
		int difference = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != t[i])
			{
				if (!difference)
					difference = true;
				else
					return false;
			}
		}

		return difference;
	}
	else
	{

		string left = "";
		for (int i = 0; i < s.length(); i++)
		{
			string right = s.substr(i+1);
			if (left + right == t) return true;
			left += s[i];
		}
		return false;
	}
	return false;
}