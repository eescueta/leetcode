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
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/


/*
[[ 1, 2, 3 ],[ 7, 8, 4 ],[ 7, 6, 5 ]]
[[ 1, 2, 3, 4 ],[ 10, 11, 12, 5 ],[ 9, 8, 7, 6 ]]
[[ 1, 2, 3, 4 ],[ 12, 13, 14, 5 ],[ 11, 16, 15, 6 ],[ 10, 9, 8, 7 ]]
[]
[[1]]
[[ 1, 2, 3, 4 ],[ 8, 7, 6, 5 ]]
[[1,2],[8,3],[7,4],[6,5]]
[[ 1, 2, 3 ],[ 8, 9, 4 ],[ 7, 6, 5 ]]
[[ 1, 2, 3, 4 ],[ 10, 11, 12, 5 ],[ 9, 8, 7, 6 ]]
[[ 1, 2, 3, 4 ],[ 12, 13, 14, 5 ],[ 11, 16, 15, 6 ],[ 10, 9, 8, 7 ]]
[]
[[1]]
[[ 1, 2, 3, 4 ],[ 8, 7, 6, 5 ]]
[[1,2],[8,3],[7,4],[6,5]]
[[1,2,3,4],[10,11,12,5],[9,8,7,6]]
[[1,2,3],[10,11,4],[9,12,5],[8,7,6]]
[[1,2,3,4],[10,11,12,5],[9,8,7,6]]
[[1,2,3],[10,11,4],[9,12,5],[8,7,6]]
*/


vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0)
		return{};
	if (matrix.size() == 1)
		return matrix[0];

	int circle = 0;

	int height = matrix.size();
	int width = matrix[0].size();

	vector<int> res;
	vector<int> newNums = { 0 };

	int step = 0; // work from outer circle to inner circle

	while (newNums.size() > 0)//dunnoyet
	{
		newNums = {};

		// top row
		for (int i = step; i < width - step && step <= height - 1 - step; i++)
		{
			newNums.push_back(matrix[step][i]);
		}
		// right column excluding top element
		for (int i = step + 1; i < height - step && width-1-step >= step; i++)
		{
			newNums.push_back(matrix[i][width - 1 - step]);
		}
		// bottom row excluding bottom right element
		for (int i = (width - 1) - step - 1; i >= step && height - 1 - step > step; i--) // add extra condition when last row is first row
		{
			newNums.push_back(matrix[height - 1 - step][i]);
		}
		//left column excluding top left element
		for (int i = (height - 1) - step - 1; i > step && step < width -1 -step; i--)
		{
			newNums.push_back(matrix[i][step]);
		}

 		res.insert(res.end(), newNums.begin(), newNums.end());
		step++;
	}

	return res;
}