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
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
[1,null,2,3]
[1,2,3,4,5,6, 7, 8,null, 9, 10]
[]
[1]
*/

vector<int> inorderTraversal(TreeNode* root) {
	if (root == NULL)
		return{};

	vector<int> results;
	stack<TreeNode*> s;
	s.push(root);
	// go down all the way on left side adding to stack
	TreeNode* leftPtr = root->left;
	while (leftPtr != NULL)
	{
		s.push(leftPtr);
		leftPtr = leftPtr->left;
	}

		
	while (s.size() > 0)
	{
		TreeNode* curr = s.top();
		results.push_back(curr->val);
		s.pop();
		if (curr->right != NULL)
		{
			s.push(curr->right);
			leftPtr = s.top()->left;
			// go down all the way on left side adding to stack
			while (leftPtr != NULL)
			{
				s.push(leftPtr);
				leftPtr = leftPtr->left;
			}
		}
	}

	return results;
}