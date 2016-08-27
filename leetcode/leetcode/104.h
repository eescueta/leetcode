#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

int maxDepth(TreeNode* root) {
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	// recursive solution
	int leftCount = maxDepth(root->left);
	int rightCount = maxDepth(root->right);

	if (leftCount > rightCount)
		return leftCount + 1;
	else
		return rightCount + 1;
}