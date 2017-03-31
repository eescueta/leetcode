#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
*/

/*
[3,9,20,null,null,15,7]
[3,9,8,4,0,1,7]
[3,9,8,4,0,1,7,null,null,null,2,5]
[6,1,null,null,3,2,5,null,null,4]
[]
[1]
*/

vector<vector<int>> verticalOrder(TreeNode* root) {
	if (root == NULL) return{};

	//vector<vector<int>> result = { { root->val } };
	vector<vector<int>> result = {};
	map<int, vector<int>> colToVal;
	int col_min = 0;
	int col_max = 0;


	queue<TreeNode*> node_queue;
	node_queue.push(root);
	queue<int> col_queue;
	col_queue.push(0);

	while (node_queue.size() > 0)
	{
		TreeNode* curr = node_queue.front();
		node_queue.pop();
		int col = col_queue.front();
		col_queue.pop();

		col_min = min(col_min, col);
		col_max = max(col_max, col);

		colToVal[col].push_back(curr->val);

		if (curr->left != NULL)
		{
			node_queue.push(curr->left);
			col_queue.push(col - 1);
		}
		if (curr->right != NULL)
		{
			node_queue.push(curr->right);
			col_queue.push(col + 1);
		}

	}

	for (int i = col_min; i <= col_max; i++)
	{
		result.push_back(colToVal[i]);
	}

	return result;
}