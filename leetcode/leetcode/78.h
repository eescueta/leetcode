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
Total Accepted: 143743
Total Submissions: 382577
Difficulty: Medium
Contributors: Admin
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
[1,2,3]
[1]
[1,2]
[1,2,3,4]
*/

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res = { {} };

	for (int i = 0; i < nums.size(); i++)
	{
		vector<vector<int>> newRes;

		// add current element to previous subsets
		for (int k = 0; k < res.size(); k++)
		{
			newRes.push_back(res[k]);
			res[k].push_back(nums[i]);
			newRes.push_back(res[k]);
		}

		res = newRes;
	}

	return res;
}