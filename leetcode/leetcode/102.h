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
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/*
[3,9,20,null,null,15,7]
[3,9,20,null,null,15,7,1]
[]
[1]
*/

vector<vector<int>> levelOrder(TreeNode* root) {
	if (root == NULL)
		return{};

	vector<vector<int>> result;

	vector<TreeNode*> currentLevel;
	currentLevel.push_back(root);

	while (currentLevel.size() > 0)
	{
		vector<TreeNode*> nextLevel;
		vector<int> currResults;

		for (int i = 0; i < currentLevel.size(); i++)
		{
			if (currentLevel[i]->left != NULL)
				nextLevel.push_back(currentLevel[i]->left);
			if (currentLevel[i]->right != NULL)
				nextLevel.push_back(currentLevel[i]->right);

			currResults.push_back(currentLevel[i]->val);
		}

		currentLevel = nextLevel;
		result.push_back(currResults);
	}

	return result;
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	if (root == NULL)
		return{};

	vector<vector<int>> result;

	vector<TreeNode*> currentLevel;
	currentLevel.push_back(root);

	while (currentLevel.size() > 0)
	{
		vector<TreeNode*> nextLevel;
		vector<int> currResults;

		for (int i = 0; i < currentLevel.size(); i++)
		{
			if (currentLevel[i]->left != NULL)
				nextLevel.push_back(currentLevel[i]->left);
			if (currentLevel[i]->right != NULL)
				nextLevel.push_back(currentLevel[i]->right);

			currResults.push_back(currentLevel[i]->val);
		}

		currentLevel = nextLevel;
		result.push_back(currResults);
	}

	reverse(result.begin(), result.end());

	return result;
}