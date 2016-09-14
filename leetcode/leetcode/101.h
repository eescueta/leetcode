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
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

/*
[]
[1]
[1,2,2,3,4,4,3]
[1,2,2,3,4,4,3,5,6,7,8,8,7,6,5]
[1,2,2,3,4,4,3,null,6,7,8,8,7,6,5]
[1,2,2,3,null,null,3]
[1,2,2,null,3,null,3]
[-64,12,18,-4,-53,null,76,null,-51,null,null,-93,3,null,-31,47,null,3,53,-81,33,4,null,-51,-44,-60,11,null,null,null,null,78,null,-35,-64,26,-81,-31,27,60,74,null,null,8,-38,47,12,-24,null,-59,-49,-11,-51,67,null,null,null,null,null,null,null,-67,null,-37,-19,10,-55,72,null,null,null,-70,17,-4,null,null,null,null,null,null,null,3,80,44,-88,-91,null,48,-90,-30,null,null,90,-34,37,null,null,73,-38,-31,-85,-31,-96,null,null,-18,67,34,72,null,-17,-77,null,56,-65,-88,-53,null,null,null,-33,86,null,81,-42,null,null,98,-40,70,-26,24,null,null,null,null,92,72,-27,null,null,null,null,null,null,-67,null,null,null,null,null,null,null,-54,-66,-36,null,-72,null,null,43,null,null,null,-92,-1,-98,null,null,null,null,null,null,null,39,-84,null,null,null,null,null,null,null,null,null,null,null,null,null,-93,null,null,null,98]
*/

bool isSymmetricHelper(TreeNode* t1, TreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 != NULL && t2 == NULL)
		return false;
	if (t1 == NULL && t2 != NULL)
		return false;
	if (t1->val != t2->val)
		return false;

	return t1->val == t2->val && isSymmetricHelper(t1->left, t2->right) && isSymmetricHelper(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	if (root->left != NULL && root->right == NULL)
		return false;
	if (root->left == NULL && root->right != NULL)
		return false;

	return isSymmetricHelper(root->left, root->right);
}


// Memory too big for this
//bool checkNullQueue(vector<TreeNode*> q)
//{
//	for (int i = 0; i < q.size(); i++)
//	{
//		if (q[i] != NULL)
//			return false;
//	}
//
//	return true;
//}
//bool isSymmetric(TreeNode* root) {
//	vector<TreeNode*> q;
//	q.push_back(root);
//
//	if (root == NULL)
//		return true;
//
//	if (root->left == NULL && root->right == NULL)
//		return true;
//
//	while (!checkNullQueue(q))
//	{
//		vector<TreeNode*> nextLevel;
//		// get nextLevel
//		for (int i = 0; i < q.size(); i++)
//		{
//			if (q[i] != NULL)
//			{
//				nextLevel.push_back(q[i]->left);
//				nextLevel.push_back(q[i]->right);
//			}
//			else
//			{
//				nextLevel.push_back(NULL);
//				nextLevel.push_back(NULL);
//			}
//		}
//
//		// check nextLevel is symmentric
//		for (int i = 0; i < nextLevel.size() / 2; i++)
//		{
//			if (nextLevel[i] == NULL && nextLevel[nextLevel.size() - 1 - i] == NULL)
//				continue;
//			if (nextLevel[i] != NULL && nextLevel[nextLevel.size() - 1 - i] == NULL)
//				return false;
//			if (nextLevel[i] == NULL && nextLevel[nextLevel.size() - 1 - i] != NULL)
//				return false;
//			if (nextLevel[i]->val != nextLevel[nextLevel.size() - 1 - i]->val)
//				return false;
//		}
//		q = nextLevel;
//	}
//
//	return true;
//}