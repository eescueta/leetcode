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
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

/*
[0,1,3,50,75]
0
99
[0,1,3,50,75,99]
0
99
[0,1,3,50,75,97]
0
99
[0,1,3,50,75,98]
0
99
[25,50,75]
0
99
[]
0
99
[50]
0
99
[]
1
1
[]
0
99
[-1]
-1
0
*/

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {

	int start = lower;

	vector<string> result;
	
	if (nums.size() == 0)
	{
		if (lower == upper)
			result.push_back(to_string(lower));
		else
			result.push_back(to_string(lower) + "->" + to_string(upper));

		return result;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (start == nums[i])
		{
			start++;
			continue;
		}
		else if (nums[i] == start + 1) // interval is length = 1
		{
			result.push_back(to_string(start));
			start = nums[i] + 1;
		}
		else // common case
		{
			int end = nums[i] - 1;
			result.push_back(to_string(start) + "->" + to_string(end));
			start = nums[i] + 1;
		}

	}

	if (start <= upper)
	{
		if (start == upper)
			result.push_back(to_string(start));
		else
			result.push_back(to_string(start) + "->" + to_string(upper));
	}

	return result;
}