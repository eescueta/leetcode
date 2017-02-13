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
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/*
[]
0
[1, 4, 3, 2, 5, 2]
3
[1, 4, 3, 2, 5, 2]
4
[1, 4, 3, 2, 5, 2]
5
[1, 4, 3, 2, 5, 2]
2
[4,3,5,3,6,3]
3
[1]
1
[]
1
[1]
2
*/

ListNode* partition(ListNode* head, int x)
{
	if (head == NULL) return NULL;

	// instantiate the different pointers we need
	ListNode* lessHead = NULL;
	ListNode* lessTail = NULL;

	ListNode* greaterHead = NULL;
	ListNode* greaterTail = NULL;

	ListNode* curr = head;

	while (curr != NULL)
	{
		// current node goes into less than partition
		if (curr->val < x)
		{
			// less than partition not initialized yet
			if (lessHead == NULL)
			{
				lessHead = curr;
				lessTail = lessHead;
			}
			else
			{
				lessTail->next = curr;
				lessTail = lessTail->next;
			}
		}
		// current node goes into greater than or equal partition
		else
		{
			// greater partition not initialized yet
			if (greaterHead == NULL)
			{
				greaterHead = curr;
				greaterTail = greaterHead;
			}
			else
			{
				greaterTail->next = curr;
				greaterTail = greaterTail->next;
			}
		}

		curr = curr->next;
	}

	if (greaterHead !=  NULL)
		greaterTail->next = NULL;

	if (lessHead != NULL)
	{
		lessTail->next = greaterHead;
		return lessHead;
	}
	else
	{
		return greaterHead;
	}
}