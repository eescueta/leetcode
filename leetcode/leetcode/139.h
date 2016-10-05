#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include "Solution.h"

using namespace std;

/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

/*
"leetcode"
["leet","code"]
"leetleetcode"
["leet","code"]
"leetacode"
["leeta", "code"]
"leetacode"
["leet", "code"]
""
["leeta", "code"]
""
[]
"abc"
[]
"abc"
["leeta", "code"]
*/

bool wordBreak(string s, unordered_set<string>& wordDict) {

	if (s == "")
		return true;
	if (wordDict.size() == 0)
		return false;

	for (int i = 1; i <= s.size(); i++)
	{
		string currWord = s.substr(0, i);
		if (wordDict.count(currWord) > 0)
		{
			string restOfString = s.substr(i);
			if (wordBreak(restOfString, wordDict))
				return true;
		}
	}

	return false;
}
