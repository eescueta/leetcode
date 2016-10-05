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
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/*
[]
[[1,4,7] [2,3,8],[20]]
[[1,2,3]];
*/

bool checkListsNull(vector<ListNode*>& lists)
{
	bool moreLeft = false;
	for (int i = 0; i < lists.size(); i++)
	{
		if (lists[i] != NULL)
		{
			moreLeft = true;
			break;
		}
	}
	return moreLeft;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0)
		return NULL;
	if (lists.size() == 1)
		return lists[0];

	ListNode* currNode = NULL;
	ListNode* headNode = NULL;

	while (checkListsNull(lists))
	{
		ListNode* newNode = new ListNode(0);
		int minVal = INT_MAX;
		int minIdx;

		//find minval
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i] == NULL)
				continue;

			if (lists[i]->val <= minVal)
			{
				minVal = lists[i]->val;
				minIdx = i;
			}
		}

		//insert into result list
		newNode->val = minVal;
		//first node
		if (currNode == NULL)
		{
			currNode = newNode;
			headNode = newNode;
		}
		else
		{
			currNode->next = newNode;
			currNode = currNode->next;
		}

		// increment appropriate list
		lists[minIdx] = lists[minIdx]->next;
	}

	return headNode;
}