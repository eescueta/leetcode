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
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

ListNode *detectCycle(ListNode *head) {

	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	if (fast == NULL || fast->next == NULL) return NULL;

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}