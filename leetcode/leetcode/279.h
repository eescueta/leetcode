#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

/*
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
*/


int numSquaresHelper(int n, vector<int>* results)
{
	while ((*results).size() - 1 != n)
	{
		int res = INT_MAX;

		for (int i = 1; i*i <= (*results).size(); i++)
		{
			if (i*i == (*results).size())
			{
				res = 1;
				break;
			}
			else
			{
				res = min(res, 1 + (*results)[(*results).size() - i*i]);
			}
		}

		(*results).push_back(res);
	}

	return (*results)[(*results).size() - 1];
}

int numSquares(int n) {

	vector<int> results;
	results.push_back(0); // n == 0, base case

	return numSquaresHelper(n, &results);
}