#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include "Solution.h"

using namespace std;

/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

/*
"1"
"69"
"88"
"818"
"010"
"20"
"10"
"101"
"96"
*/

map<char, char> digits;

bool isStrobogrammatic(string num) {
	digits['6'] = '9';
	digits['1'] = '1';
	digits['0'] = '0';
	digits['8'] = '8';
	digits['9'] = '6';

	string rev;

	for (int i = num.size() - 1; i >= 0; i--)
	{
		if (digits.count(num[i]) > 0)
		{
			rev.push_back(digits[num[i]]);
		}
		else
			return false;
	}

	return num == rev;

}