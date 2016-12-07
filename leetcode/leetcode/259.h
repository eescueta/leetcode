#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?
*/

/*
[]
0
[-2, 0 1, 3]
2
[5,3,2,1,0]
7
*/

int twoSumSmaller(vector<int>& nums, int target, int startIdx) {
	int res = 0;

	int itLeft = startIdx;
	int itRight = nums.size() - 1;

	while (itLeft < itRight)
	{
		if (nums[itLeft] + nums[itRight] < target)
		{
			res += itRight - itLeft;
			itLeft++;
		}
		else
		{
			itRight--;
		}
		//if (nums[itLeft] < nums[itRight])
		//	itLeft++;
		//else
		//	itRight--;
	}
	
	return res;
}

int threeSumSmaller(vector<int>& nums, int target) {
	if (nums.size() < 3)
		return 0;

	sort(nums.begin(), nums.end());

	int res = 0;

	for (int i = 0; i < nums.size()-2; i++)
	{
		res += twoSumSmaller(nums, target - nums[i], i + 1);
	}

	return res;
}