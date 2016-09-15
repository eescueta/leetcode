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
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

/*
0
9
1
*/

vector<int> grayCode(int n) {
	if (n == 0)
		return{ 0 };
	if (n == 1)
		return{ 0, 1 };

	vector<int> results = { 0, 1 };
	int bitmask = 2;

	int currentBit = 1;

	while (currentBit < n)
	{
		for (int i = results.size() - 1; i >= 0; i--)
		{
			int newEntry = results[i] | bitmask;
			results.push_back(newEntry);
		}
		bitmask = bitmask << 1;
		currentBit += 1;
	}

	return results;
}