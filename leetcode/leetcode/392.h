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
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.
*/

/*
"abc"
"ahbgdc"
"abc"
"ahcgdb"
"axc"
"ahbgdc"
"abc"
"abc"
"abcd"
"abc"
*/

bool isSubsequence(string s, string t) {
	if (s.length() > t.length())
		return false;
	if (s == t)
		return true;
	if (s.length() == t.length() && s != t)
		return false;

	int itS = 0;
	int itT = 0;

	while (itS < s.length() && itT < t.length())
	{
		if (s[itS] == t[itT])
		{
			itS++;
			itT++;
		}
		else
			itT++;
	}

	if (itS < s.length())
		return false;
	else
		return true;
}