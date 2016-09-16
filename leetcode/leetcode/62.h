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
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

/*
1
2
1
1
3
7
23
12
*/

struct coordinates
{
	int x;
	int y;

	bool operator=(const coordinates &o) {
		return x == o.x && y == o.y;
	}

	bool operator<(const coordinates &o) const {
		return x < o.x || (x == o.x && y < o.y);
	}
};


int uniquePathsHelper(int m, int n, map<coordinates, int>* numPaths)
{
	coordinates c;
	c.x = m;
	c.y = n;
	if ((*numPaths).find(c) != (*numPaths).end())
		return (*numPaths)[c];


	if (m == 1)
	{
		int uP = uniquePathsHelper(m, n - 1, numPaths);
		(*numPaths)[c] = uP;
		return uP;
	}
	else if (n == 1)
	{
		int uP = uniquePathsHelper(m - 1, n, numPaths);
		(*numPaths)[c] = uP;
		return uP;
	}
	else
	{
		int uP = uniquePathsHelper(m, n - 1, numPaths) + uniquePathsHelper(m - 1, n, numPaths);
		(*numPaths)[c] = uP;
		return uP;
	}

}

int uniquePaths(int m, int n) {
	map<coordinates, int> numPaths;

	// init base case
	coordinates c;
	c.x = 1;
	c.y = 1;
	numPaths[c] = 1;

	return uniquePathsHelper(m, n, &numPaths);
}