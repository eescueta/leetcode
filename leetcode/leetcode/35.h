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
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

/*
[1]
0
[1,3,5,6]
5
[1,3,5,6]
2
[1,3,5,6]
7
[1,3,5,6]
0
[2,3,5,6]
1
*/

int searchInsert(vector<int>& nums, int target) {
	int it = 0;

	if (target == 0)
		return 0;

	while (it < nums.size())
	{
		// target in array
		if (nums[it] == target)
			return it;

		// passed targets would be location
		if (nums[it] > target)
			return it;

		it++;
	}

	//target is bigger than all elements in array
	return it;


}