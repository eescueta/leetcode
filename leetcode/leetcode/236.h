#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == p || root == q || root == NULL)
		return root;

	TreeNode* lcaLeft = lowestCommonAncestor(root->left, p, q);
	TreeNode* lcaRight = lowestCommonAncestor(root->right, p, q);

	if (lcaLeft != NULL && lcaRight != NULL)
		return root;
	else if (lcaLeft == NULL && lcaRight != NULL)
		return lcaRight;
	else if (lcaLeft != NULL && lcaRight == NULL)
		return lcaLeft;
	else
		return NULL;
}
