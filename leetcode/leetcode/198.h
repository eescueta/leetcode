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
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

/*
[5,5,6,0,1]
[5,6,0,1,5]
[6,5,3,3,4]
[5,5,6,0,7]
[1]
[]
[1,1]
[6,6,4,8,4,3,3,10]
*/

/* naive solution */
int robHelper(vector<int>& nums, int startIndex)
{
	int firstHouse = 0;
	int result = 0;

	// base cases
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	if (startIndex > nums.size() - 1)
		return 0;
	if (startIndex == nums.size() - 1)
		return nums[nums.size()-1];

	for (int i = startIndex; i < nums.size(); i++)
	{
		if (nums[i] > firstHouse)
		{
			firstHouse = nums[i];

			// get answer for rest of array excluding the next element
			int restResult = robHelper(nums, i + 2);
			if (firstHouse + restResult > result)
				result = firstHouse + restResult;
		}
	}

	return result;
}

int rob(vector<int>& nums) 
{
	return robHelper(nums, 0);
}

