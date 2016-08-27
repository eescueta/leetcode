#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Invert a binary tree
*/

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)
		return root;

	// base case
	if (root->left == NULL && root->right == NULL)
		return root;

	// invert lower levels
	TreeNode* tempLeft = invertTree(root->left);
	TreeNode* tempRight = invertTree(root->right);

	// invert at root
	root->right = tempLeft;
	root->left = tempRight;

	return root;
}