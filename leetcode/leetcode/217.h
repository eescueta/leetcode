#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

/*
[]
[1,2,3]
[3,2,1]
[1,2,3,1,4,5]
[1]
*/

bool containsDuplicate(vector<int>& nums) {
	map<int, int> numCounter;

	for (int i = 0; i < nums.size(); i++)
	{
		numCounter[nums[i]]++;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (numCounter[nums[i]] > 1)
			return true;
	}


	// no duplicates
	return false;
}