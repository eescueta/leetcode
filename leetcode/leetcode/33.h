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
*/

int search(vector<int>& nums, int target) {
	
	if (nums.size() == 0) return -1;

	int start = 0;
	int end = nums.size() - 1;
	int mid = ((end - start) / 2) + start;

	while (start < end && start + 1 != end)
	{
		mid = ((end - start) / 2) + start;
		if (nums[start] == target)
			return start;
		if (nums[end] == target)
			return end;
		if (nums[mid] == target)
			return mid;

		// mid greater than start
			// if element is between start and mid, go left
			// else go right
		// mid smaller than end
			// if element is between mid and end, go right
			// else go left

		if (nums[mid] > nums[start])
		{
			if (target < nums[mid] && target > nums[start])
				end = mid - 1;
			else
				start = mid + 1;
		}
		else if (nums[mid] < nums[end])
		{
			if (target > nums[mid] && target < nums[end])
				start = mid + 1;
			else
				end = mid - 1;
		}
		
		//return -1;
	}

	if (nums[start] == target) return start;
	if (nums[end] == target) return end;

	return -1;
}
