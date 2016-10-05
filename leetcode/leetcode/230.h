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
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
*/

/*
[1]
1
[5,3,6,2,4,null, null, 1]
4
[5,3,6,2,4,null, null, 1]
6
[5,3,6,2,4,null, null, 1]
1
[5,3,6,2,4,null, null, 1]
2
[5,3,6,2,4,null, null, 1]
3
[5,3,6,2,4,null, null, 1]
5
[7,6,8,2,5, null, 9,1,null, 4, null,null, null, null, null, 3]
1
[7,6,8,2,5, null, 9,1,null, 4, null,null, null, null, null, 3]
2
[7,6,8,2,5, null, 9,1,null, 4, null,null, null, null, null, 3]
3
[7,6,8,2,5, null, 9,1,null, 4, null,null, null, null, null, 3]
4
[7,6,8,2,5, null, 9,1,null, 4, null,null, null, null, null, 3]
5
[7,6,8,2,5, null, 9,1,null, 4, null,null, null, null, null, 3]
6
[7,6,8,2,5, null, 9,1,null, 4, null,null, null, null, null, 3]
7
*/

int kthSmallest(TreeNode* root, int k) {
	stack<TreeNode*> s;
	// get smallest element while pushing onto stack
	TreeNode* currNode = root;
	while (currNode->left != NULL)
	{
		s.push(currNode);
		currNode = currNode->left;
	}

	int count = 1;

	while (count < k)
	{
		if (currNode->right != NULL)
		{
			currNode = currNode->right;
			while (currNode->left != NULL)
			{
				s.push(currNode);
				currNode = currNode->left;
			}
			count++;
		}
		else
		{
			currNode = s.top();
			s.pop();
			count++;
		}
	}

	return currNode->val;
}