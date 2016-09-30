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
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

/*
[0,1,2,4,5,7]
[0,1,2,4,5,6,7]
[0,2,3,4,5,7]
[]
[1]
*/

vector<string> summaryRanges(vector<int>& nums) {
	vector<string> results;

	if (nums.size() == 0)
		return {};
		
	vector<int> currentRange = {};

	for (int i = 0; i < nums.size(); i++)
	{
		if (currentRange.size() == 0 || currentRange[currentRange.size() - 1] == nums[i] - 1)
			currentRange.push_back(nums[i]);
		else
		{
			if (currentRange.size() > 1)
				results.push_back(to_string(currentRange[0]) + "->" + to_string(currentRange[currentRange.size() - 1]));
			else
				results.push_back(to_string(currentRange[0]));

			currentRange = {};
			currentRange.push_back(nums[i]);
		}
	}

	if (currentRange.size() > 1)
		results.push_back(to_string(currentRange[0]) + "->" + to_string(currentRange[currentRange.size() - 1]));
	else
		results.push_back(to_string(currentRange[0]));

	return results;
}