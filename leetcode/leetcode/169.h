#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

/*
[1]
[2,2,2,3,3]
[1,2,1]
*/

int majorityElement(vector<int>& nums) {
	map<int, int> numMap;

	for (int i = 0; i < nums.size(); i++)
	{
		numMap[nums[i]]++;
	}

	double majorityThreshold = nums.size() / 2.0;

	// loop through map
	for (auto const &ent1 : numMap)
	{
		if (ent1.second*1.0 > majorityThreshold)
			return ent1.first;
	}

}