#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
[1]
[1,1,2,3,3]
[1,1,2,2,3]
[1,2,2,3,3]
*/

int singleNumber(vector<int>& nums) {
	// sort the vector
	sort(nums.begin(), nums.end(), mySortFunction);

	for (int i = 0; i < nums.size(); i++)
	{
		// beginning edge case
		if (i == 0)
		{
			if (nums[1] != nums[0])
				return nums[0];
		}
		// end edge case
		else if (i == nums.size() - 1)
		{
			if (nums[nums.size() - 2] != nums[nums.size() - 1])
				return nums[nums.size() - 1];
		}
		else
		{
			if (nums[i - 1] != nums[i] && nums[i + 1] != nums[i])
				return nums[i];
		}
	}

	return 0;

}