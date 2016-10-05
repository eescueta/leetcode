#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include "Solution.h"

using namespace std;

/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/

/*
[3,5,2,1,6,4]
[]
[1]
*/

void wiggleSort(vector<int>& nums) {
	if (nums.size() <= 1)
		return;

	sort(nums.begin(), nums.end());

	int it1 = 0;
	int it2 = nums.size() - 1;

	vector<int> res;

	while (it1 < it2)
	{
		res.push_back(nums[it1]);
		res.push_back(nums[it2]);
		it1++;
		it2--;
	}

	// last number
	if (it1 == it2)
	{
		res.push_back(nums[it1]);
	}

	nums = res;
}