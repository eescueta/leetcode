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
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

/*
[1]
1
[3,2,1,5,6,4]
1
[3,2,1,5,6,4]
2
[3,2,1,5,6,4]
3
[3,2,1,5,6,4]
4
[3,2,1,5,6,4]
5
[3,2,1,5,6]
4
[3,2,1,5,6]
3
[3,2,1,5,6]
2
[3,2,1,5,6]
1
[5,2,4,1,3,6,0]
2
[3,3,3,3,3,3,3,3,3]
1
[3,3,3,3,4,3,3,3,3]
1
*/


int findKthLargest(vector<int>& nums, int k) {

	int start = 0;
	int end = nums.size() - 1;

	while (start < end)
	{
		int pivot = nums[start];
		int itLeft = start + 1;
		int itRight = end;

		while (itLeft < itRight)
		{
			if (nums[itLeft] > pivot && nums[itRight] <= pivot)
			{
				swap(nums[itLeft], nums[itRight]);
				itLeft++;
				itRight--;
			}
			else if (nums[itLeft] <= pivot) itLeft++;
			else if (nums[itRight] > pivot) itRight--;
		}

		int pivotIdx = nums[itRight] < pivot ? itRight : itRight - 1;
		swap(nums[start], nums[pivotIdx]);

		if (nums.size() - k == pivotIdx) return nums[pivotIdx];
		else if (nums.size() - k < pivotIdx) end = pivotIdx - 1;
		else if (nums.size() - k > pivotIdx) start = pivotIdx + 1;
	}



	return nums[start];
}