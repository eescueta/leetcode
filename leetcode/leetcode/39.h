#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

/*
[2,3,6,7]
7
[2,3,4,6,7]
7
[]
0
[5]
5
*/

void combinationSumHelper(vector<int>& candidates, int target, vector<int> currentArray, vector <vector<int>>* results, int startIdx)
{
	if (target == 0)
	{
		(*results).push_back(currentArray);
		return;
	}
	else if (target < 0)
		return;
	else
	{
		for (int i = startIdx; i < candidates.size(); i++)
		{
			vector<int> v = currentArray;
			v.push_back(candidates[i]);
			combinationSumHelper(candidates, target - candidates[i], v, results, i);
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> results;

	for (int i = 0; i < candidates.size(); i++)
	{
		combinationSumHelper(candidates, target - candidates[i], { candidates[i] }, &results, i);
	}

	return results;
}