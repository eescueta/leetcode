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
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/*
[]
[0]
[1,2,3,null,4,5,6,null, 7,null, null, null,null, 8]
[1,2,3,null,4,5,6,null, 7]
[1,2,3,9,4,5,6,null, 7]
*/

int isBalancedHelper(TreeNode* node)
{
	if (node == NULL)
		return 0;
	
	int depthLeft = isBalancedHelper(node->left);
	int depthRight = isBalancedHelper(node->right);

	if (depthLeft == -1 || depthRight == -1)
		return -1;
	if (abs(depthLeft - depthRight) >= 2)
		return -1;

	return 1 + max(depthLeft, depthRight);
}


bool isBalanced(TreeNode* root) {
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;

	if (isBalancedHelper(root) >= 0)
		return true;
	else
		return false;
}