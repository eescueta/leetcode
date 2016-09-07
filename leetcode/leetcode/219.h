#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that
nums[i] = nums[j] and the difference between i and j is at most k.
*/

/*
[]
[1,2,3]
[3,2,1]
[1,2,3,1,4,5]
[1]
*/

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if (nums.size() <= 1)
		return false;

	map<int, int> numCount; // counts occurences of numbers
	map<int, vector<int>> numIndices; // records indices of numbers

	for (int i = 0; i < nums.size(); i++)
	{
		if (!numCount[nums[i]]) // number has not been recorded yet
		{
			numCount[nums[i]]++;
			numIndices[nums[i]].push_back(i);
		}
		else
		{
			for (int j = 0; j < numIndices[nums[i]].size(); j++)
			{
				if (abs(i - numIndices[nums[i]][j]) <= k)
					return true;
			}
			numCount[nums[i]]++;
			numIndices[nums[i]].push_back(i);
		}
	}

	return false;
}