#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
	//Solution();
	//~Solution();
	vector<int> twoSum(vector<int>& nums, int target);
};


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

static bool mySortFunction(int i, int j) { return (i<j); }