#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/*
[]
[1]
[1,1,2]
[1,2,2]
[1,1,2,3,3]
[1,1,2,2,2,3,3]
[1,1,1,2,2,3,3,3]
*/

void deleteDuplicatesHelper(ListNode* prev, ListNode* curr)
{
	if (prev == NULL)
	{
		deleteDuplicatesHelper(curr, curr->next);
		return;
	}

	//donezo
	if (curr == NULL)
		return;

	if (prev->val == curr->val)
	{
		prev->next = curr->next;
		delete curr;
		deleteDuplicatesHelper(prev, prev->next);
	}
	else
	{
		deleteDuplicatesHelper(curr, curr->next);
	}
}

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL)
		return NULL; 

	deleteDuplicatesHelper(NULL, head);
	return head;
}