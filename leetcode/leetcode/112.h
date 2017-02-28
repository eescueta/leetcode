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
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

/*
[]
1
[5, 4, 8, 11, null, 13,4, 7, 2, null, null, null, 1]
22
[10,5,-3,3,2,null,11,3,-2,null,1]
3
*/

void pathSumHelper(TreeNode* curr, int sum, int& resultCount, vector<int>& currentPath)
{
	if (curr == NULL)
		return;

	int currentNumber = curr->val;
	if (currentNumber == sum) resultCount++;

	int sumPath = currentNumber;
	for (int i = currentPath.size() - 1; i >= 0; i--)
	{
		sumPath += currentPath[i];
		if (sumPath == sum) resultCount++;
	}

	currentPath.push_back(currentNumber);
	pathSumHelper(curr->left, sum, resultCount, currentPath);
	pathSumHelper(curr->right, sum, resultCount, currentPath);
	currentPath.pop_back();
}

int pathSum(TreeNode* root, int sum) {
	int result = 0;
	vector<int> p = {};
	pathSumHelper(root, sum, result, p);
	return result;
}