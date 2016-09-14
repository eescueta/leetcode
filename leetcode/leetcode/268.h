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
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

/*
[0]
[3,1,0]
*/

int missingNumber(vector<int>& nums) {
	int solution = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		solution = solution ^ nums[i];
	}

	for (int i = 0; i <= nums.size(); i++)
	{
		solution = solution ^ i;
	}
	return solution;
}