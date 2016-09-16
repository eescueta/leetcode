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
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

/*
[1]
1
[]
0
[2,4,6,8,1,1,1,1]
4
[1,3,5,7]
4
[2,4,6,8,1,1,1]
4
[1,3,5]
3
[2,4,6,8]
4
[]
0
[0]
0
[1]
1
[4,5,6,0,0,0]
3
[1,2,3]
3
[-1,0,0,3,3,3,0,0,0]
6
[1,2,2]
3
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int itOne = m - 1;
	int itTwo = n - 1;
	int itAll = m + n - 1;

	if (itTwo < 0)
		return;

	while (itAll >= 0)
	{
		if (itTwo < 0)
			return;
		else if (itOne < 0)
		{
			nums1[itAll] = nums2[itTwo];
			itTwo--;
		}
		else if (nums1[itOne] < nums2[itTwo])
		{
			nums1[itAll] = nums2[itTwo];
			itTwo--;
		}
		else
		{
			nums1[itAll] = nums1[itOne];
			itOne--;
		}

		itAll--;
	}
}