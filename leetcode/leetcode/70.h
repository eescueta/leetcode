#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*
1
3
5
2
123
532
23
12
643
23
654
34
786
*/

int climbStairsHelper(int n, map<int, int> &archive) {
	if (n == 0)
		return 1;

	if (archive[n] > 0)
		return archive[n];

	// current step
	int result = 0;

	if (n >= 2)
	{
		result += climbStairsHelper(n - 2, archive);
	}
	if (n >= 1)
	{
		result += climbStairsHelper(n - 1, archive);
	}

	archive[n] = result;

	return result;
}

int climbStairs(int n) {
	map<int, int> archiveResults;
	return climbStairsHelper(n, archiveResults);
}

