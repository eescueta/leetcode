#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include "Solution.h"

using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

/*
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
5
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
20
*/



bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0) return false;
	if (matrix[0].size() == 0) return false;

	vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));

	queue<int> rowToVisit;
	queue<int> colToVisit;
	rowToVisit.push(0);
	colToVisit.push(0);

	while (rowToVisit.size() > 0 && colToVisit.size() > 0)
	{
		int row = rowToVisit.front();
		rowToVisit.pop();
		int col = colToVisit.front();
		colToVisit.pop();

		visited[row][col] = 1;

		if (matrix[row][col] == target) return true;
		if (matrix[row][col] > target) continue;

		// go down if can and not visited
		if (row < matrix.size() - 1 && visited[row + 1][col] == 0)
		{
			rowToVisit.push(row + 1);
			colToVisit.push(col);
		}
		// go right if can and not visited
		if (col < matrix[0].size() - 1 && visited[row][col + 1] == 0)
		{
			rowToVisit.push(row);
			colToVisit.push(col+1);
		}
	}


	return false;
}