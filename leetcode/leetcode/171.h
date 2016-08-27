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
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/

int titleToNumber(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	int multiplier = 1;
	int val = 0;

	for (int i = s.size() - 1; i >= 0; i--)
	{
		val += (s[i] - 'a' + 1) * multiplier;
		multiplier *= 26;
	}

	return val;
}