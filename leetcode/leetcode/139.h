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
"iamace"
["i", "a", "am", "ace"]
"abc"
["leeta", "code"]
""
["leeta", "code"]
""
[]
"abc"
[]
*/

bool wordBreak(string s, unordered_set<string>& wordDict) {
	if (s == "")
		return true;

	//vector<bool> v(s.length(), false);
	//vector<vector<bool>> archive;
	//for (int i = 0; i < s.length(); i++)
	//{
	//	archive.push_back(v);
	//}

	//// form matrix diagonal first
	//for (int i = 0; i < s.length(); i++)
	//{
	//	if (wordDict.count(string(1, s[i])) > 0)
	//	{
	//		archive[i][i] = true;
	//	}
	//}

	for (int size = 2; size <= s.length(); size++)
	{

		for (int i = 0; i <= s.length() - size; i++)
		{
			string a = s.substr(i, size);
			if (wordDict.count(a) > 0)
			{
				//archive[i][i + size - 1] = true;
				continue;
			}


			//split point
			for (int j = i + 1; j < i + size; j++)
			{
				string s1 = s.substr(i, j - i);
				string s2 = s.substr(j, size - (j - i));
				if (wordDict.count(s1) > 0 && wordDict.count(s2) > 0)
				{
					//archive[i][i + size - 1] = true;
					wordDict.insert(s1 + s2);
					break;
				}

			}
		}
	}


	return wordDict.count(s);
}

//bool wordBreak(string s, unordered_set<string>& wordDict) {
//
//	if (s == "")
//		return true;
//	if (wordDict.size() == 0)
//		return false;
//
//	for (int i = 1; i <= s.size(); i++)
//	{
//		string currWord = s.substr(0, i);
//		if (wordDict.count(currWord) > 0)
//		{
//			string restOfString = s.substr(i);
//			if (wordBreak(restOfString, wordDict))
//				return true;
//		}
//	}
//
//	return false;
//}
