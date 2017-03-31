#pragma once
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
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

/*
[[1,0,0],[-1,0,3]]
[[7,0,0],[0,0,0],[0,0,1]]
*/


vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {

	//initialize to all zeroes
	vector<vector<int>> results (A.size(), vector<int>(B[0].size(), 0));

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			if (A[i][j] != 0)
			{
				for (int k = 0; k < B[0].size(); k++)
				{
					if (B[j][k] != 0)
						results[i][k] += A[i][j] * B[j][k];
				}
			}
		}
	}

	return results;
}