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
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

/*
[1]
[0,1,2,3,4,5]
[1,2,3,4,5,0]
[2,3,4,5,0,1]
[3,4,5,0,1,2]
[4,5,0,1,2,3]
[5,0,1,2,3,4]
*/

int findMin(vector<int>& nums) {

	if (nums.size() == 1)
		return nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < nums[i - 1])
			return nums[i];
	}

	return nums[0];

}