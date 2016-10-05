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
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/


/*
[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
*/


void wallsAndGates(vector<vector<int>>& rooms) {
	if (rooms.size() == 0)
		return;

	int maxY = rooms.size();
	int maxX = rooms[0].size();

	for (int i = 0; i < maxY; i++) // col
	{
		for (int j = 0; j < maxX; j++) // row
		{
			if (rooms[i][j] != 0)
				continue; 

			queue<int> qY;
			queue<int> qX;

			qY.push(i);
			qX.push(j);

			//int steps = 1;

			while (qY.size() > 0 && qX.size() > 0)
			{
				int currY = qY.front();
				int currX = qX.front();
				qY.pop();
				qX.pop();

				int currSteps = rooms[currY][currX] + 1;

				//up
				if (currY - 1 >= 0 && rooms[currY - 1][currX] > currSteps)
				{
					rooms[currY - 1][currX] = currSteps;
					qY.push(currY - 1);
					qX.push(currX);
				}
				//down
				if (currY + 1 < maxY && rooms[currY + 1][currX] > currSteps)
				{
					rooms[currY + 1][currX] = currSteps;
					qY.push(currY + 1);
					qX.push(currX);
				}
				//left
				if (currX - 1 >= 0 && rooms[currY][currX-1] > currSteps)
				{
					rooms[currY][currX-1] = currSteps;
					qY.push(currY);
					qX.push(currX-1);
				}
				//right
				if (currX + 1 < maxX && rooms[currY][currX + 1] > currSteps)
				{
					rooms[currY][currX + 1] = currSteps;
					qY.push(currY);
					qX.push(currX + 1);
				}

				//steps++;
			}
		}
	}

}
