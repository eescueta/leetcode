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
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*
*/

bool hasCycle(ListNode *head) {
	if (head == NULL)
		return false;

	ListNode* ptr1 = head;
	ListNode* ptr2 = head;

	while (ptr1->next != NULL && ptr2->next != NULL && ptr2->next->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;

		if (ptr1 == ptr2)
			return true;
	}

	return false;
}