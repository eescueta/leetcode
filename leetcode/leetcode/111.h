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
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/*
[]
[1]
[1,2,3,null,4,5,null, 6,7,null, null, 8]
*/

int minDepth(TreeNode* root) {
	// base cases
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	
	if (root->left == NULL)
		return 1 + minDepth(root->right);
	else if (root->right == NULL)
		return 1 + minDepth(root->left);
	else
		return min(1 + minDepth(root->left), 1 + minDepth(root->right));
}