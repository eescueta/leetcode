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
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

/*
[[0]]
[[0,0,0],[0,1,0],[0,0,0]]
[[0,0,0,1],[0,1,0,0],[0,0,0,0]]
*/

int pathsHelper(int x, int y, vector<vector<int>>& countArchive)
{
	if (countArchive[x][y] != -1) return countArchive[x][y];

	if (x == 0)
		countArchive[x][y] = pathsHelper(x, y - 1, countArchive);
	if (y == 0)
		countArchive[x][y] = pathsHelper(x - 1, y, countArchive);
	else
		countArchive[x][y] = pathsHelper(x-1, y-1, countArchive);

	return countArchive[x][y];

}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	vector<vector<int>> countArchive(obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), -1));
	countArchive[0][0] = 1;

	for (int i = 0; i < obstacleGrid.size(); i++)
	{
		for (int j = 0; j < obstacleGrid[0].size(); j++)
		{
			if (obstacleGrid[i][j] == 1) countArchive[i][j] == 0;
		}
	}

	return pathsHelper(countArchive.size() - 1, countArchive[0].size() - 1, countArchive);
}