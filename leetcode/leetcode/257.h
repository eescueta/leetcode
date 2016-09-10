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
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

1
/   \
2     3
\
5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

/*
[1,2,3,null,5]
[1,2,3,4,5]
[1,2,3,null,5,6,7,null, null, 8]
[1,2,3,null,5,6,7,null]
[]
[1]
*/

void binaryTreePathsHelper(TreeNode* current, string currentString, vector<string>* results)
{
	currentString = currentString + "->" + to_string(current->val);

	//check if current is a leaf
	if (current->left == NULL && current->right == NULL)
	{
		(*results).push_back(currentString);
		return;
	}

	// recursive calls
	if (current->left != NULL)
		binaryTreePathsHelper(current->left, currentString, results);
	if (current->right != NULL)
		binaryTreePathsHelper(current->right, currentString, results);
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> results;
	if (root == NULL)
		return results;
	// chekc if root is a leaf
	if (root->left == NULL && root->right == NULL)
	{
		results.push_back(to_string(root->val));
		return results;
	}

	if (root->left != NULL)
		binaryTreePathsHelper(root->left, to_string(root->val), &results);

	if (root->right != NULL)
		binaryTreePathsHelper(root->right, to_string(root->val), &results);

	return results;
}