#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

/*
""
""
"a"
""
""
"a"
"a"
"a"
"ADOBEOCDEBANC"
"ABC"
"ADOBECODEBANC"
"ABCB"
"bba"
"ab"
*/


// return true if current substring s contains t
bool doesContain(vector<int> subCount, vector<int>tCount)
{
	for (int i = 0; i < 256; i++)
	{
		if (subCount[i] < tCount[i]) return false;
	}
	return true;
}

string minWindowOld(string s, string t) {
	if (t == "") return s;
	if (s == "") return "";

	vector<int> tCount(256, 0);
	vector<int> subCount(256, 0);

	// fill t count
	for (int i = 0; i < t.length(); i++)
		tCount[t[i]]++;

	int maxLength = INT_MAX;
	string currentResult = "";
	int startOfSubstring = -1;

	// loop through string
	for (int i = 0; i < s.length(); i++)
	{
		if (tCount[s[i]] > 0)
		{
			subCount[s[i]]++;
			if (currentResult == "" && startOfSubstring == -1)
				startOfSubstring = i;

			if (doesContain(subCount, tCount))
			{
				while (subCount[s[startOfSubstring]] > tCount[s[startOfSubstring]])
				{
					subCount[s[startOfSubstring]]--;
					startOfSubstring++;

					while (tCount[s[startOfSubstring]] == 0)
						startOfSubstring++;
				}

				string currSubstring = s.substr(startOfSubstring, i - startOfSubstring + 1);
				if (currSubstring.length() < maxLength)
				{
					maxLength = currSubstring.length();
					currentResult = currSubstring;
				}
			}
		}
	}

	return currentResult;
}