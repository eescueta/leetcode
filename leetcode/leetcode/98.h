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
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/

/*
[2,1,3]
[1,2,3]
[5,4,7,3,null, 6, 9]
[10,5,15,null,null,6,20]
[10,5,15,null,20,13,20]
[1]
[]
[1,1]
[0, -1]
[-2147483648,null,2147483647]
[-2147483648,null,2147483647,null,2147483647]
[-2147483648,-2147483648,2147483647]
*/
bool isValidBSTHelper(TreeNode* node, int min, int max, bool minSet, bool maxSet)
{
	if (node == NULL)
		return true;

	if ((minSet && node->val <= min) || (maxSet && node->val >= max))
		return false;

	if (node->right == NULL)
		return isValidBSTHelper(node->left, min, node->val, minSet, true);
	if (node->left == NULL)
		return isValidBSTHelper(node->right, node->val, max, true, maxSet);
	else
		return isValidBSTHelper(node->left, min, node->val, minSet, true) && isValidBSTHelper(node->right, node->val, max, true, maxSet);
}

bool isValidBST(TreeNode* root) {
	if (root == NULL || (root->right == NULL && root->left == NULL))
		return true;
	if (root->right == NULL)
		return (isValidBSTHelper(root->left, INT_MIN, root->val, false, true));
	if (root->left == NULL)
		return (isValidBSTHelper(root->right, root->val, INT_MAX, true, false));
	else
		return (isValidBSTHelper(root->left, INT_MIN, root->val, false, true)) && (isValidBSTHelper(root->right, root->val, INT_MAX, true, false));
}