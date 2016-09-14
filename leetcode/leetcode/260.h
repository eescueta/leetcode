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
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

/*
[1,2,1,3,2,5]
[1,1,3,3,4,5]
*/

vector<int> singleNumber(vector<int>& nums) {
	int XorAll = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		XorAll = XorAll ^ nums[i];
	}

	int leastSignificantOne = XorAll & -XorAll;

	int num1 = 0;
	int num2 = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] & leastSignificantOne)
			num1 = num1 ^ nums[i];
		else
			num2 = num2 ^ nums[i];
	}

	vector<int> results;
	results.push_back(num1);
	results.push_back(num2);
	return results;
}