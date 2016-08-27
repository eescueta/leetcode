#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

/*
[0]
[0,0,1]
[0,1,0,3,12]
[0,1,2,0,3,12]
[0,1,0,3,12,0]
[0,1,2,0,3,12,0]
*/

void moveZeroes(vector<int>& nums) {
	// keep track of zeros at the end
	int currEnd = nums.size();

	for (int i = 0; i < currEnd; i++)
	{
		if (nums[i] == 0)
		{
			for (int j = i; j < currEnd - 1; j++)
			{
				nums[j] = nums[j + 1];
			}

			nums[currEnd - 1] = 0;
			i--;
			currEnd--;
		}
	}
}