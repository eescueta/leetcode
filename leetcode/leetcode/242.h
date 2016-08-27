#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

/*
""
""
"anagram"
"nagaram"
"rat"
"cat"
"abc"
"bc"
*/

bool isAnagram(string s, string t) {
	if (s.size() != t.size())
		return false;

	map<char, int> tBank;

	for (int i = 0; i < t.size(); i++)
	{
		tBank[t[i]]++;
	}

	for (int j = 0; j < s.size(); j++)
	{
		if (tBank[s[j]] > 0)
			tBank[s[j]]--;
		else
			return false;
	}

	return true;
}