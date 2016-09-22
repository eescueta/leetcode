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
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/*
0
1
2
3
4
*/

vector<vector<int>> generateMatrix(int n) {
	if (n == 0)
		return{};
	if (n == 1)
		return{ {1} };

	vector<vector<int>> result;

	// initialize matrix with 0s
	vector<int> startRow;
	for (int i = 0; i < n; i++)
	{
		startRow.push_back(0);
	}
	for (int i = 0; i < n; i++)
	{
		result.push_back(startRow);
	}

	int col = 0;
	int row = 0;
	result[row][col] = 1;
	int lastNumber = 1;

	while (lastNumber < n*n)
	{
		bool top = (row != 0 && result[row - 1][col] == 0);
		bool down = (row != n - 1 && result[row + 1][col] == 0);
		bool right = (col != n - 1 && result[row][col + 1] == 0);
		bool left = (col != 0 && result[row][col - 1] == 0);


		if (!top && !left && right)
		{
			// move right
			col++;
			result[row][col] = lastNumber+1;
		}
		else if (!top && !right && down)
		{
			// move down
			row++;
			result[row][col] = lastNumber+1;
		}
		else if (!down && !right && left)
		{
			// move left
			col--;
			result[row][col] = lastNumber+1;
		}
		else if (!left && !down && up)
		{
			// move up
			row--;
			result[row][col] = lastNumber+1;
		}		
		lastNumber++;

	}

	return result;
}