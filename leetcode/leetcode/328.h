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
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

/*
[1,2,3,4,5,6,7,8]
[1,2,3,4,5]
[]
[1]
*/

ListNode* oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* first = head;
	ListNode* second = head->next;

	ListNode* oddPtr = head;
	ListNode* evenPtr = head->next;

	while (oddPtr != NULL && evenPtr != NULL)
	{
		if (oddPtr->next != NULL)
			oddPtr->next = oddPtr->next->next;
		if (evenPtr->next != NULL)
			evenPtr->next = evenPtr->next->next;

		oddPtr = oddPtr->next;
		evenPtr = evenPtr->next;
	}

	ListNode* firstEnd = first;
	while (firstEnd->next != NULL)
		firstEnd = firstEnd->next;

	firstEnd->next = second;
	return first;
}