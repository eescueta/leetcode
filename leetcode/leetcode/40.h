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
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
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
[10,1,2,7,6,1,5]
8
[18,6,18,18,11,30,18,33,24,18,17,15,29,8,18,30,28,34,10,28,20,34,5,15,18,28,34,7,10,8,33,23,31,16,29,7,33,12,27,23,18,9,25,34,34,30,29,27,21,26,21,6,25,21,16,30,6,15,32,11,10,23,30,29,26,24]
28
*/

void combinationSum2Helper(vector<int>& candidates, int target, vector<int> currentArray, vector <vector<int>>* results, int startIdx)
{
	if (target == 0)
	{
		// check if current array is already in results
		sort(currentArray.begin(), currentArray.end());
		for (int i = 0; i < (*results).size(); i++)
		{
			if ((*results)[i] == currentArray)
				return;
		}
		(*results).push_back(currentArray);
		return;
	}
	else if (target < 0)
		return;
	else
	{
		for (int i = startIdx+1; i < candidates.size(); i++)
		{
			vector<int> v = currentArray;
			v.push_back(candidates[i]);
			combinationSum2Helper(candidates, target - candidates[i], v, results, i);
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> results;

	if (candidates.size() == 0)
		return{ {} };

	for (int i = 0; i < candidates.size(); i++)
	{
		combinationSum2Helper(candidates, target - candidates[i], { candidates[i] }, &results, i);
	}

	return results;
}