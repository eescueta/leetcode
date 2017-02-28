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
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

/*
*/
TreeNode* inorderSuccessorHelper(TreeNode* curr, TreeNode* p, vector<TreeNode*>& list)
{
	if (curr == NULL)
		return NULL;

	TreeNode* left = inorderSuccessorHelper(curr->left, p, list);
	
	if (left)
		return left;

	if (list.size() > 0 && list.back() == p)
		return curr;

	list.push_back(curr);

	TreeNode* right = inorderSuccessorHelper(curr->right, p, list);
	return right;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	vector<TreeNode*> list;
	
	return inorderSuccessorHelper(root, p, list);
}