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
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*
[2,3,4]
6
[2, 7, 11, 15]
9
*/


vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> result = { 0, 0 };
	int idx1 = 0;
	int idx2 = numbers.size() - 1;

	while (idx1 != idx2)
	{
		if (numbers[idx1] + numbers[idx2] == target)
		{
			result[0] = idx1+1;
			result[1] = idx2+1;
			return result;
		}
		else if (numbers[idx1] + numbers[idx2] > target)
		{
			idx2--;
		}
		else if (numbers[idx1] + numbers[idx2] < target)
		{
			idx1++;
		}
	}

	return result;
}