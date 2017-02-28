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
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

/*
[""]
["eat", "tea", "tan", "ate", "nat", "bat"]
*/


vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	map<map<char,int>, int> stringMapToIndex;

	for (int i = 0; i < strs.size(); i++)
	{
		map<char, int> charCount;
		for (int k = 0; k < strs[i].length(); k++)
		{
			charCount[strs[i][k]]++;
		}

		// case where no existing anagrams yet
		if (stringMapToIndex.find(charCount) == stringMapToIndex.end())
		{
			vector<string> n = { strs[i] };
			res.push_back(n);
			stringMapToIndex[charCount] = res.size() - 1;
		}
		// case where we insert into map
		else
		{
			res[stringMapToIndex[charCount]].push_back(strs[i]);
		}
	}

	return res;
}

vector<vector<string>> groupAnagramsSTRINGS(vector<string>& strs) {

	vector<vector<string>> res;
	map<string, int> sortedStringToIndex;

	for (int i = 0; i < strs.size(); i++)
	{
		string s = strs[i];
		string sorted = strs[i];
		sort(sorted.begin(), sorted.end());

		// case where no existing anagrams yet
		if (sortedStringToIndex.find(sorted) == sortedStringToIndex.end())
		{
			vector<string> n = { s };
			res.push_back(n);
			sortedStringToIndex[sorted] = res.size() - 1;
		}
		// case where we insert into map
		else
		{
			res[sortedStringToIndex[sorted]].push_back(s);
		}
	}

	return res;
}