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
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

/*
[1,2,3]
4
[1,2,3]
7
[]
0
[]
1
[4,2,1]
32
*/

int combinationSum4Helper(vector<int>& nums, int target, map<int, int>* targetCount)
{
	int count = 0;

	if ((*targetCount).count(target) > 0)
		return (*targetCount)[target];

	if (nums.size() == 0 && target == 0)
		return 1;

	for (int i = 0; i < nums.size(); i++)
	{
		if (target - nums[i] == 0)
		{
			count += 1;
		}
		else if (nums[i] < target)
		{
			count += combinationSum4Helper(nums, target - nums[i], targetCount);
		}
	}

	(*targetCount)[target] = count;
	return count;
}

int combinationSum4(vector<int>& nums, int target) {
	map<int, int> targetCount; // memoize

	return combinationSum4Helper(nums, target, &targetCount);
}