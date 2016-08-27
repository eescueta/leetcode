#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;

	if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
		return false;

	if (p->val != q->val)
		return false;

	bool leftMatch = isSameTree(p->left, q->left);
	bool rightMatch = isSameTree(p->right, q->right);

	return leftMatch && rightMatch;
}