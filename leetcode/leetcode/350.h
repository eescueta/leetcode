#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/*
[]
[]
[1, 2, 2, 1]
[2,2]
[2,2]
[1,2,2,1]
[1,2,3,4,5,6]
[1,2,3,1,2]
[4,7,9,7,6,7]
[5,0,0,6,1,6,2,2,4]
*/

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	// sort the vectors
	sort(nums1.begin(), nums1.end(), mySortFunction);
	sort(nums2.begin(), nums2.end(), mySortFunction);

	// get bigger smaller vectors;
	vector<int> big;
	vector<int> small;
	if (nums1.size() >= nums2.size())
	{
		big = nums1;
		small = nums2;
	}
	else
	{
		big = nums2;
		small = nums1;
	}

	// result vector
	vector<int> intersection;

	map<int, int> smallRecord;
	int smallMax = 0;

	// archive small array
	for (int i = 0; i < small.size(); i++)
	{
		smallRecord[small[i]]++;
		if (small[i] > smallMax)
			smallMax = small[i];
	}

	// read big array
	for (int i = 0; (i < big.size() && big[i] <= smallMax); i++)
	{
		if (smallRecord[big[i]] > 0)
		{
			intersection.push_back(big[i]);
			smallRecord[big[i]]--;
		}
	}

	return intersection;
}