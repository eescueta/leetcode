#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "Solution.h"
#include <cstdint>
#include <cctype>

using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
*/

/*
[1,null ,2,3]
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
[]
[1]
*/


vector<int> preorderTraversal(TreeNode* root) {
	if (root == NULL)
		return{};

	stack<TreeNode*> rightNodes;
	vector<int> result;

	rightNodes.push(root);

	// process all right nodes by going down their left branch
	while (rightNodes.size() > 0)
	{
		TreeNode* currNode = rightNodes.top();
		rightNodes.pop();
		while (currNode != NULL)
		{
			result.push_back(currNode->val);
			if (currNode->right != NULL)
				rightNodes.push(currNode->right);
				currNode = currNode->left;
		}
	}

	return result;
}