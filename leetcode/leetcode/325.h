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
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

/*
[1,-1,5,-2,3]
3
[-2,-1,2,1]
1
[-2,-1,2,1]
0
[]
5
[5]
5
[5]
1
[]
0
[1,0,-1]
-1
*/


int maxSubArrayLen(vector<int>& nums, int k) {
	if (nums.size() == 0) return 0;

	// key - sum
	// value - index where sum of all previous elements is equal to sum
	map<int, int> sumToIndex;
	int currSum = 0;
	int currMax = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		currSum += nums[i];

		if (currSum == k)
		{
			currMax = i + 1;
		}
		else if (sumToIndex.find(currSum - k) != sumToIndex.end())
		{
			currMax = max(currMax, i - sumToIndex[currSum - k] + 1);
		}

		// forgot this
		if (sumToIndex.find(currSum) != sumToIndex.end())
			sumToIndex[currSum] = min(sumToIndex[currSum], i + 1);
		else
			sumToIndex[currSum] = i + 1;
	}

	return currMax;
}