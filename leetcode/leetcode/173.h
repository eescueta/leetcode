#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/*
[]
[1]
[12,6,13,3,9,null, 14,1,5,7,11,null, null, null, 2, 4, null, null, 8, 10]
*/

class BSTIterator {
public:
	stack<TreeNode*> s;

	BSTIterator(TreeNode *root) {
		TreeNode* t;
		t = root;
		while (t != NULL)
		{
			s.push(t);
			t = t->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return s.size();
	}

	/** @return the next smallest number */
	int next() {
		if (s.size() == 0)
			return NULL;

		TreeNode* pop = s.top();
		s.pop();

		TreeNode* nextLevel = pop->right;
		while (nextLevel != NULL)
		{
			s.push(nextLevel);
			nextLevel = nextLevel->left;
		}

		return pop->val;
	}
};