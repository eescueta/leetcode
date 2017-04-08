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
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

*/

/*
7
[2,3,1,2,4,3]
*/



int minSubArrayLen(int s, vector<int>& nums) {

	int start = 0;
	int sum = 0;

	int minLength = INT_MAX;

	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];

		if (sum >= s)
		{
			while (sum - nums[start] >= s)
			{
				sum -= nums[start];
				start++;
			}
			minLength = min(minLength, i - start + 1);
		}
	}

	return minLength;

}