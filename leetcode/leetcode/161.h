#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"
#include <cstdint>

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

Subscribe to see which companies asked this question
*/

/*
[]
1
[5, 4, 8, 11, null, 13, 4, 7, 2, null, 1]
22
[5, 4, 8, 11, null, 13, 4, 7, 2, null, 1, null, null, null, null, -1]
21
[5, 4, 8, 11, null, 13, 4, 7, 2, null, 1, null, null, null, null, 4]
21
[1,2]
1
*/

bool hasPathSumHelper(TreeNode* currentNode, int sum, int cumulativeSum)
{
	if (currentNode->val + cumulativeSum == sum && currentNode->left == NULL && currentNode->right == NULL)
		return true;

	int newCumulativeSum = currentNode->val + cumulativeSum;

	if (currentNode->left == NULL && currentNode->right == NULL)
		return false;
	else if (currentNode->left == NULL)
		return hasPathSumHelper(currentNode->right, sum, newCumulativeSum);
	else if (currentNode->right == NULL)
		return hasPathSumHelper(currentNode->left, sum, newCumulativeSum);
	else 
		return hasPathSumHelper(currentNode->left, sum, newCumulativeSum) || hasPathSumHelper(currentNode->right, sum, newCumulativeSum);
}

bool hasPathSum(TreeNode* root, int sum) {
	if (root == NULL)
		return false;

	return hasPathSumHelper(root, sum, 0);
}