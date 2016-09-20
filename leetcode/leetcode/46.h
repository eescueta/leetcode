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
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
[1,2,3]
[1]
[1,2]
[1,2,3,4]
*/

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> results;
	if (nums.size() <= 1)
		return{ nums };

	if (nums.size() == 2)
	{
		results.push_back(nums);
		reverse(nums.begin(), nums.end());
		results.push_back(nums);
		return results;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		vector<int> cpy = nums;
		cpy.erase(cpy.begin() + i);
		vector<vector<int>> r2 = permute(cpy);
		for (int j = 0; j < r2.size(); j++)
		{
			r2[j].insert(r2[j].begin(), nums[i]);
			results.push_back(r2[j]);
		}
	}

	return results;


}