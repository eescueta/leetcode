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
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
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

void nQueens(int row, int gridSize, vector<int>& rowToColumn, vector<vector<int>>& results)
{
	if (row == gridSize) results.push_back(rowToColumn);

	for (int col = 0; col < gridSize; col++)
	{
		if (isValidSpot(row, col, rowToColumn))
		{
			rowToColumn[row] = col;
			nQueens(row + 1, gridSize, rowToColumn, results);
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<int>> results;
	vector<int> rowToColumn(n, 0);

	nQueens(0, n, rowToColumn, results);

	// get strings of queens
	vector<vector<string>> board;

	for (int i = 0; i < results.size(); i++)
	{
		vector<string> rows;

		for (int j = 0; j < results[i].size(); j++)
		{
			string r(n, '.');
			r[results[i][j]] = 'Q';
			rows.push_back(r);
		}

		board.push_back(rows);
	}


	return board;
}