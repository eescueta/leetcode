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
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

/*
[[9,9,4],[6,6,8],[2,1,1]]
[[3,4,5],[3,2,6],[2,2,1]]
[[11,10,9],[8,7,8],[7,6,7]]
[[]]
*/

int numRows;
int numCols;
int totalMax;

void longestPathHelper(vector<vector<int>>& matrix, vector<vector<int>>& lengthArchive, int row, int col)
{
	// already archived
	if (lengthArchive[row][col] >= 0)
		return;

	int maxLength = 0;
	int val = matrix[row][col];

	//up
	if (row > 0 && matrix[row - 1][col] > val)
	{
		longestPathHelper(matrix, lengthArchive, row - 1, col);
		maxLength = max(maxLength, lengthArchive[row-1][col]);
	}
	//down
	if (row < numRows - 1 && matrix[row + 1][col] > val)
	{
		longestPathHelper(matrix, lengthArchive, row + 1, col);
		maxLength = max(maxLength, lengthArchive[row+1][col]);
	}
	//left
	if (col > 0 && matrix[row][col - 1] > val)
	{
		longestPathHelper(matrix, lengthArchive, row, col - 1);
		maxLength = max(maxLength, lengthArchive[row][col-1]);
	}
	//right
	if (col < numCols - 1 && matrix[row][col + 1] > val)
	{
		longestPathHelper(matrix, lengthArchive, row, col + 1);
		maxLength = max(maxLength, lengthArchive[row][col + 1]);
	}

	lengthArchive[row][col] = maxLength + 1;
	if (maxLength + 1 > totalMax)
		totalMax = maxLength + 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return 0;

	numRows = matrix.size();
	numCols = matrix[0].size();

	totalMax = 0;

	// initialize memoize archive
	vector<vector<int>> lengthArchive;
	for (int i = 0; i < numRows; i++)
	{
		vector<int> v(numCols, -1);
		lengthArchive.push_back(v);
	}

	//call helper function, build lengh archive
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			longestPathHelper(matrix, lengthArchive, i, j);
		}
	}

	return totalMax;
}