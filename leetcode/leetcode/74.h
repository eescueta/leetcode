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

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

/*
[[1,3,5,7],[10,11,16,20],[23,30,34,50]]
3
[[1,3,5,7],[10,11,16,20],[23,30,34,50]]
15
[]
0
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0) return false;

	// binary search to find row
	int start = 0;
	int end = matrix.size() - 1;
	int mid = 0;

	while (start < end && start + 1 != end)
	{
		mid = ((end - start) / 2) + start;

		// array is where we want to be
		if (matrix[mid].front() <= target && matrix[mid].back() >= target)
			break;

		// array is too small
		if (matrix[mid].front() < target && matrix[mid].back() < target)
		{
			start = mid + 1;
		}
		// array is too big
		if (matrix[mid].front() > target && matrix[mid].back() > target)
		{
			end = mid - 1;
		}
	}

	int row = mid;
	if (start + 1 == end || start == end)
	{
		if (matrix[start].front() <= target && matrix[start].back() >= target)
			row = start;
		else if (matrix[end].front() <= target && matrix[end].back() >= target)
			row = end;
	}

	start = 0;
	end = matrix[row].size() - 1;

	// binary search to find element in row
	while (start < end && start + 1 != end)
	{
		mid = ((end - start) / 2) + start;

		if (matrix[row][mid] == target) return true;

		if (matrix[row][mid] > target)
		{
			end = mid - 1;
		}

		if (matrix[row][mid] < target)
		{
			start = mid + 1;
		}
	}

	if (start + 1 == end || start == end)
	{
		if (matrix[row][start] == target || matrix[row][end] == target)
			return true;
	}

	return false;
}



