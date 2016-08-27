#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
Each element in the result must be unique.
The result can be in any order.
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

static bool intersectionSort(int i, int j) { return (i<j); }

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	// sort vectors
	std::sort(nums1.begin(), nums1.end(), intersectionSort);
	std::sort(nums2.begin(), nums2.end(), intersectionSort);

	vector<int> small;
	vector<int> big;
	vector<int> intersection;

	// get smaller/bigger vectors
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

	int itSmall = 0;
	int itBig = 0;

	while (itSmall < small.size())
	{
		// get rid of duplicates in smaller array, ensures no dupes in intersection
		if (itSmall > 0 && small[itSmall] == small[itSmall - 1])
		{
			itSmall++;
			continue;
		}

		while (itBig < big.size() && itSmall < small.size())
		{
			if (small[itSmall] == big[itBig])
			{
				intersection.push_back(small[itSmall]);
				itSmall++;
				break;
			}
			else if (big[itBig] < small[itSmall])
			{
				itBig++;
			}
			else if (big[itBig] > small[itSmall])
			{
				itSmall++;
			}
		}

		if (itBig >= big.size())
			break;
	}

	return intersection;
}