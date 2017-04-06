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
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

/*
"123"
6
"232"
8
"105"
5
"00"
0
"3456237490"
9191
"6105"
111
"105"
5
*/

void addOpHelpler(vector<string>& results, string currString, long currVal, int currMult, int idx, string num, int target)
{
	if (idx == num.length())
	{
		if (currVal == target)
			results.push_back(currString);
		return;
	}

	string sub = "";

	for (int i = idx; i < num.size(); i++)
	{
		sub += num.substr(i, 1);
		long val = stol (sub);

		// initial
		if (idx == 0)
		{
			addOpHelpler(results, sub, val, val, i + 1, num, target);
		}
		else
		{
			// add
			addOpHelpler(results, currString + "+" + sub, currVal + val, val, i + 1, num, target);
			// substract
			addOpHelpler(results, currString + "-" + sub, currVal - val, -val, i + 1, num, target);
			// multiply
			addOpHelpler(results, currString + "*" + sub, currVal - currMult + (currMult*val), currMult*val, i + 1, num, target);
		}
		
		if (i == idx && num[i] == '0')
			break;
	}
}

vector<string> addOperators(string num, int target) {

	vector<string> results;
	addOpHelpler(results, "", 0, 0, 0, num, target);

	return results;
}