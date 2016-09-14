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
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

/*
[0,0]
[1,2,3,4]
[]
[1]
*/


vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.size() <= 0)
		return{};

	if (nums.size() == 0)
		return nums;

	vector<int> results;
	// initialize results with 1's
	for (int i = 0; i < nums.size(); i++)
	{
		results.push_back(1);
	}

	// first pass through left to right
	int acc = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		results[i] = acc;
		acc *= nums[i];
	}

	// second pass through right to left
	acc = 1;
	for (int i = nums.size()-1; i >= 0; i--)
	{
		results[i] *= acc;
		acc *= nums[i];
	}
	return results;
}