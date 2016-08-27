#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

/*
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

/*
"a"
"b"
"aa"
"ab"
"aa"
"aab"

*/

bool canConstruct(string ransomNote, string magazine) {
	map<char, int> magazineMap;

	for (int i = 0; i < magazine.size(); i++)
	{
		magazineMap[magazine[i]]++;
	}

	for (int j = 0; j < ransomNote.size(); j++)
	{
		if (magazineMap[ransomNote[j]] > 0)
			magazineMap[ransomNote[j]]--;
		else
			return false;
	}

	return true;
}