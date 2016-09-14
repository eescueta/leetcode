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
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
*/

/*
""
""
"egg"
"add"
"egge"
"addi"
"foo"
"bar"
"paper"
"title"
"Paper"
"title"
"egg"
"egg"
"egg"
"eii"
"ab"
"aa"
"ab"
"ca"
*/

bool isIsomorphic(string s, string t) {
	if (s.length() != t.length())
		return false;

	map<int, char> correspondingLetters;
	map<int, char> correspondingLettersReverse; // checks t to i

	for (int i = 0; i < s.length(); i++)
	{
		if (correspondingLetters[s[i]]) // letter already corresponds to a charcter in other string
		{
			if (correspondingLetters[s[i]] != t[i])
				return false;
		}
		else if (correspondingLettersReverse[t[i]])
		{
			if (correspondingLettersReverse[t[i]] != s[i])
				return false;
		}
		else
		{
			correspondingLetters[s[i]] = t[i];
			correspondingLettersReverse[t[i]] = s[i];
		}
	}

	return true;
}