#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/


/*
[0]
[]
[2,1]
[2,0]
[1,0]
[0,1]
[0,2]
[0,1,1,1,1,0,0,0,1,1,1]
[2,1,1,1,2,1,2,1,2]
[1,2,2,1,2,1,2,1]
[2,1,2,0,1,2,1,2,1,0,0,0]
*/


void sortColors(vector<int>& nums) {
	if (nums.size() <= 1)
		return;

	int leftPtr = 0;
	int rightPtr = nums.size() - 1;
	while (nums[leftPtr] == 0)
		leftPtr++;
	while (nums[rightPtr] == 2)
		rightPtr--;

	for (int i = leftPtr; i <= rightPtr; i++)
	{
		if (nums[i] == 0)
		{
			if (i != leftPtr)
			{
				nums[i] = nums[leftPtr];
				nums[leftPtr] = 0;
				i--;
			}
			leftPtr++;
		}
		else if (nums[i] == 2)
		{
			nums[i] = nums[rightPtr];
			nums[rightPtr] = 2;
			rightPtr--;
			i--;
		}
	}
}