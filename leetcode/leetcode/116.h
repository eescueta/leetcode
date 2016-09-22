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
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/


struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


void connect(TreeLinkNode *root) {

	if (root == NULL)
		return;

	vector<TreeLinkNode*> currentLevel;
	currentLevel.push_back(root);

	while (currentLevel.size() > 0)
	{
		for (int i = 0; i < currentLevel.size() - 1; i++)
		{
			currentLevel[i]->next = currentLevel[i + 1];
		}

		currentLevel[currentLevel.size() - 1]->next = NULL;

		vector<TreeLinkNode*> nextLevel;
		for (int i = 0; i < currentLevel.size(); i++)
		{
			if (currentLevel[i]->left != NULL)
				nextLevel.push_back(currentLevel[i]->left);
			if (currentLevel[i]->right != NULL)
				nextLevel.push_back(currentLevel[i]->right);
		}

		currentLevel = nextLevel;
	}
}