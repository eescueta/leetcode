#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include "Solution.h"

using namespace std;

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
*/

/*
[]
[1,2,3,null,null,4,5]
[1]
*/

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == NULL)
			return "[]";
		
		string res = "[";

		vector<string> nodeVals;

		queue<TreeNode*> q;
		q.push(root);
		nodeVals.push_back(to_string(root->val));

		while (q.size() > 0)
		{
			TreeNode* front = q.front();
			q.pop();

			if (front->left != NULL)
			{
				q.push(front->left);
				nodeVals.push_back(to_string(front->left->val));
			}
			else
			{
				nodeVals.push_back("");
			}

			if (front->right != NULL)
			{
				q.push(front->right);
				nodeVals.push_back(to_string(front->right->val));
			}
			else
			{
				nodeVals.push_back("");
			}
		}

		int lastIdx = nodeVals.size() - 1;
		while (nodeVals[lastIdx] == "")
		{
			lastIdx--;
		}

		for (int i = 0; i <= lastIdx; i++)
		{
			if (nodeVals[i] != "")
				res += nodeVals[i];
			else
				res += "null";

			if (i != lastIdx)
			{
				res += ",";
			}
		}

		res += "]";

		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "[]")
			return NULL;

		vector<string> nodeVals;

		string currVal = "";
		for (int i = 0; i < data.length(); i++)
		{
			if (data[i] == ',')
			{
				nodeVals.push_back(currVal);
				currVal = "";
			}
			else if (data[i] != '[' && data[i] != ']')
			{
				currVal += data[i];
			}
		}

		nodeVals.push_back(currVal);

		queue<TreeNode*> q;

		TreeNode* res = new TreeNode(stoi(nodeVals[0]));
		q.push(res);
		int it = 1;

		while (it < nodeVals.size())
		{
			TreeNode* front = q.front();
			q.pop();

			if (nodeVals[it] != "null")
			{
				TreeNode* left = new TreeNode(stoi(nodeVals[it]));
				front->left = left;
				q.push(left);
			}

			it++;

			if (it >= nodeVals.size())
				break;

			if (nodeVals[it] != "null")
			{
				TreeNode* right = new TreeNode(stoi(nodeVals[it]));
				front->right = right;
				q.push(right);
			}

			it++;
		}
		return res;
	}
};
