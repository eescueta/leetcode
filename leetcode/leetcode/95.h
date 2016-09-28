#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
0
1
2
3
4
5
*/

TreeNode* addTreeOffset(TreeNode* root, int offset)
{
	if (root == NULL)
		return NULL;

	root->val += offset;
	root->left = addTreeOffset(root->left, offset);
	root->right = addTreeOffset(root->right, offset);

	return root;
}

vector<TreeNode*> generateTreeHelper(int n, vector<TreeNode*> &solutionArchive) {

	if (n < solutionArchive.size())
		return solutionArchive[n];

}

vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> solutionArchive;
	solutionArchive.push_back(NULL);

	TreeNode* one = new TreeNode(1);
	solutionArchive.push_back(one);

	return generateTreeHelper(n, solutionArchive);
}