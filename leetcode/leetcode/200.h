#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <sstream>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

11111
10001
10001
11111

10111
10101
11101
*/


/*
["11110","11010","11000","00000"]
["11000","11000","00100","00011"]
["11111","10001","10001","11111"]
["11111","11111","11111","11111"]
["00000","00000","00000","00000"]
["10111","10101","11101"]
["11111011111111101011","01111111111110111110","10111001101111111111","11110111111111111111","10011111111111111111","10111111011101110111","01111111111101101111","11111111111101111011","11111111110111111111","11111111111111111111","01111111011111111111","11111111111111111111","11111111111111111111","11111011111110111111","10111110111011110111","11111111111101111110","11111111111110111100","11111111111111111111","11111111111111111111","11111111111111111111"]
*/

int numIslands(vector<vector<char>>& grid) {
	//[i][j]
	//[y][x]
	int island = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			queue<vector<int>> q;

			if (grid[i][j] == '1')
			{
				q.push({ i, j });
				grid[i][j] = 'x'; // remove square

				while (q.size() > 0)
				{
					int X = q.front()[1];
					int Y = q.front()[0];
					q.pop();


					//up
					if (Y > 0 && grid[Y - 1][X] == '1')
					{
						q.push({ Y - 1, X });
						grid[Y - 1][X] = 'x';
					}
					//down
					if (Y < grid.size() - 1 && grid[Y+1][X] == '1')
					{
						q.push({ Y + 1, X });
						grid[Y + 1][X] = 'x';
					}
					//left
					if (X > 0 && grid[Y][X - 1] == '1')
					{
						q.push({ Y, X - 1 });
						grid[Y][X - 1] = 'x';
					}
					//right
					if (X < grid[0].size() - 1 && grid[Y][X + 1] == '1')
					{
						q.push({ Y, X + 1 });
						grid[Y][X + 1] = 'x';
					}
				}

				island++;
			}

		}
	}
	return island;
}