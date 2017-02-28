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
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

/*
[]
5
[15,16,19,20,25,1,3,4,5,7,10,14]
5
[1]
1
[]
5
[1,3]
0
[1,3,1,1,1]
3
[1,1,1,3,1]
3
[1,1,1,2,3]
3
[1,1,1,2,3]
2
[1,1,1,2,3]
1
[2,3,1,1,1]
3
[2,3,1,1,1]
2
[2,3,1,1,1]
1
[4,5,6,7,0,1,2]
0
[2,2,2,0,0,1]
0
*/

bool searchHelper(vector<int>& nums, int target, int start, int end)
{
	if (nums[start] == target) return true;
	if (nums[end] == target) return true;
	if (start >= end || start + 1 == end) return false;

	int mid = ((end - start) / 2) + start;

	if (nums[mid] == target) return true;

	if (nums[start] < nums[mid])
	{
		if (target < nums[mid] && target > nums[start])
			return searchHelper(nums, target, start, mid - 1);
		else
			return searchHelper(nums, target, mid + 1, end);
	}
	else if (nums[mid] < nums[end])
	{
		if (target > nums[mid] && target < nums[end])
			return searchHelper(nums, target, mid + 1, end);
		else
			return searchHelper(nums, target, start, mid - 1);
	}
	else
	{
		if (nums[mid] == nums[end] && nums[mid] != nums[start])
			return searchHelper(nums, target, start, mid - 1);
		else if (nums[mid] != nums[end] && nums[mid] == nums[start])
			return searchHelper(nums, target, mid + 1, end);
		else
			return searchHelper(nums, target, start, mid - 1) || searchHelper(nums, target, mid + 1, end);
	}

	// left side is in order
		// target is in left side
		// target is not in left side

	// right side is in order
		// target is in right side
		// target is not in right side

	//else mid = end
		// if mid = start go both sides
		// else go left

	// only reached if array is not sorted
	return false;

}

bool search(vector<int>& nums, int target) {

	if (nums.size() == 0) return false;

	return searchHelper(nums, target, 0, nums.size() - 1);

}
