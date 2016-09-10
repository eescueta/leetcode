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
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
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


vector<vector<int>> generate(int numRows) {
	vector<vector<int>> results = {};

	for (int i = 0; i < numRows; i++)
	{
		vector<int> row;
		for (int j = 0; j < i+1; j++)
		{
			// first row
			if (i == 0)
			{
				row.push_back(1);
				continue;
			}

			if (j == 0 || j == i)
				row.push_back(1);
			else
				row.push_back(results[i - 1][j - 1] + results[i - 1][j]);
		}
		results.push_back(row);
	}

	return results;
}