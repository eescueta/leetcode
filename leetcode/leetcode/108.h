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
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
[1,2,3,4,5,6,7,8]
[3,5,7]
[]
[1]
*/


TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {

	if (start == end)
		return NULL;

	int mid = ((end - start) / 2) + start;

	TreeNode* t = new TreeNode(nums[mid]);

	t->left = sortedArrayToBSTHelper(nums, start, mid);
	t->right = sortedArrayToBSTHelper(nums, mid + 1, end);
	return t;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.size() == 0)
		return NULL;
	else if (nums.size() == 1)
		return new TreeNode(nums[0]);

	return sortedArrayToBSTHelper(nums, 0, nums.size());
}