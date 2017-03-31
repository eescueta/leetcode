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
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

/*
1
4
5
6
*/

bool isValidSpot(int row, int col, const vector<int>& rowToColumn)
{
	for (int i = 0; i < row; i++)
	{
		// we dont have to check row

		// check column
		if (rowToColumn[i] == col)
			return false;

		// check diagonal
		if (abs(row - i) == abs(col - rowToColumn[i]))
			return false;

	}

	return true;
}

void nQueens(int row, int gridSize, vector<int>& rowToColumn, int& results)
{
	if (row == gridSize) results++;

	for (int col = 0; col < gridSize; col++)
	{
		if (isValidSpot(row, col, rowToColumn))
		{
			rowToColumn[row] = col;
			nQueens(row + 1, gridSize, rowToColumn, results);
		}
	}
}

int totalNQueens(int n) {
	int results = 0;
	vector<int> rowToColumn(n, 0);

	nQueens(0, n, rowToColumn, results);
	return results;
}