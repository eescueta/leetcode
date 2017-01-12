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
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

/*
[-2,1,-3,4,-1,2,1,-5,4]
[-2,1,3,4,-1,2,1,-5,4]
[500,1,-3,4,-1,2,1,-5,4]
[-2,1,-3,4,-1,2,1,-5,500]
[-4, -3, -2, -1]
[]
[1]
*/

int maxSubArray(vector<int>& nums) {
	int res = INT_MIN;
	int currentSum = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		//currentMax = max(currentMax + nums[i], nums[i]);
		//res = max(res, currentSum);
		if (nums[i] < 0 && nums[i] > res)
		{
			res = nums[i];
			currentSum = 0;
			//continue;
		}
		else
		{
			currentSum += nums[i];
			res = max(currentSum, res);
			if (currentSum < 0)
				currentSum = 0;
		}
	}

	return res;
}