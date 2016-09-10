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
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

/*
0
1
2
3
4
5
6
*/


vector<int> getRow(int rowIndex) {
	if (rowIndex == 0)
		return {1};
	if (rowIndex == 1)
		return{ 1, 1 };

	vector<int> currRow = { 1, 1 };

	for (int i = 2; i <= rowIndex; i++)
	{
		vector<int> nextRow;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				nextRow.push_back(1);
			else
				nextRow.push_back(currRow[j] + currRow[j - 1]);
		}

		currRow = nextRow;
	}

	return currRow;
}