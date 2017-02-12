#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.


Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Show Company Tags
Show Tags
Show Similar Problems

*/


/*
[[0]]
[[]]
[]
[[0,4,1],[8,5,2],[9,6,0]]
[[7,4,1],[8,0,2],[9,6,3]]
[[0,4,1],[8,0,2],[9,6,3]]
[[7,0,1],[8,5,2],[9,0,3]]
[[7,4,1],[0,5,0],[9,6,3]]
*/


void setZeroes(vector<vector<int>>& matrix) {
	int firstZeroRow = -1;


	// find first row with a zero
	for (int i = 0; i < matrix.size(); i++)
	{
		bool foundRow = false;
		for (int k = 0; k < matrix[i].size(); k++)
		{
			if (matrix[i][k] == 0)
			{
				firstZeroRow = i;
				foundRow = true;
				break;
			}
		}
		if (foundRow) break;
	}

	// no zeroes
	if (firstZeroRow < 0) return;
	
	vector<int> zeroRow(matrix[0].size()); // create a row of all zeros

	// set rows to zero execept for the first zero row
	for (int i = firstZeroRow + 1; i < matrix.size(); i++)
	{
		bool isZeroRow = false;
		for (int k = 0; k < matrix[i].size(); k++)
		{
			if (matrix[i][k] == 0)
			{
				// set row to zero
				//matrix[i] = zeroRow;
				matrix[firstZeroRow][k] = 0; // record zero row for columns
				isZeroRow = true;
			}
		}

		if (isZeroRow)
			matrix[i] = zeroRow;
	}

	// set columns to zero using values recorded in the first zero row
	for (int i = 0; i < matrix[firstZeroRow].size(); i++)
	{
		if (matrix[firstZeroRow][i] == 0)
		{
			for (int j = 0; j < matrix.size(); j++)
			{
				matrix[j][i] = 0;
			}
		}
	}

	// finally, set the first zero row to all zeroes
	matrix[firstZeroRow] = zeroRow;
}