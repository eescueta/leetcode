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
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/


/*
[]
[[1]]
[[1,2],[3,4]]
[[1,2,3],[4,5,6],[7,8,9]]
[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
[[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
*/

// reverse columns, then switch over diagnoal
void rotate(vector<vector<int>>& matrix) {
	if (matrix.size() <= 1)
		return;

	// reverse columns
	for (int i = 0; i < matrix.size(); i++)
	{

		for (int j = 0; j < matrix.size() / 2; j++)
		{
			int tmp = matrix[j][i];

			matrix[j][i] = matrix[matrix.size() - 1 - j][i];
			matrix[matrix.size() - 1 - j][i] = tmp;
		}
	}

	// switch over diagonal
	for (int i = 0; i < matrix.size(); i++) // rows
	{
		for (int j = i + 1; j < matrix.size(); j++)
		{
			int tmp = matrix[i][j]; 
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}

	return;
}