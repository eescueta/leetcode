#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


/*
"cbaebabacd"
"abc"
"abab"
"ba"
"asdf"
"dsf"
"dsf"
"asdf"
"asdf"
""
*/

bool archiveMatch(map<char, int> sArchive, map<char, int> pArchive)
{
	bool isMatch = true;
	for (map<char, int>::iterator it = pArchive.begin(); it != pArchive.end(); it++)
	{
		if (sArchive[it->first] != it->second)
		{
			isMatch = false;
			break;
		}
	}
	return isMatch;
}

vector<int> findAnagrams(string s, string p) {
	vector<int> res = {};
	if (p.size() > s.size())
		return res;

	map<char, int> sArchive;
	map<char, int> pArchive;
	for (int i = 0; i < p.size(); i++)
	{
		sArchive[s[i]]++;
		pArchive[p[i]]++;
	}

	if (archiveMatch(sArchive, pArchive))
		res.push_back(0);

	for (int i = p.size(); i < s.size(); i++)
	{
		sArchive[s[i - p.size()]]--;
		sArchive[s[i]]++;
		if (archiveMatch(sArchive, pArchive))
			res.push_back(i - (p.size() - 1));
	}

	return res;
}