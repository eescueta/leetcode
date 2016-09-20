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
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/

/*
[]
[1]
[1, 2, 3, null, 5, null, 4]
[1, 2, 3, 4, 5, 6, null, 7, 8, 9, 10, null, null, 11, null, 12, null, 13, null, 14, null, 15]
*/

vector<int> rightSideView(TreeNode* root) {
	if (root == NULL)
		return{};

	if (root->left == NULL && root->right == NULL)
		return{ root->val };

	vector<int> results;
	
	vector<TreeNode*> currentLevel;
	currentLevel.push_back(root);

	while (currentLevel.size() > 0)
	{
		results.push_back(currentLevel[currentLevel.size() - 1]->val);

		vector<TreeNode*> nextLevel;
		for (int i = 0; i < currentLevel.size(); i++)
		{
			if (currentLevel[i]->left != NULL)
				nextLevel.push_back(currentLevel[i]->left);
			if (currentLevel[i]->right != NULL)
				nextLevel.push_back(currentLevel[i]->right);
		}

		currentLevel = nextLevel;
	}

	return results;
}