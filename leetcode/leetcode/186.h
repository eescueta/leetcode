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
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
*/

void reverseWords(string &s) {
	reverse(s.begin(), s.end());
	int startIdx = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			reverse(s.begin() + startIdx, s.begin() + i);
			startIdx = i + 1;
		}
		else if (i == s.length() - 1)
			reverse(s.begin() + startIdx, s.end());
	}
}