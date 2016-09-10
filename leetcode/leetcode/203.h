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
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/*
[]
1
[1]
1
[1,1,1,2]
1
[2,1,1,1]
1
[6,2,6,5,6]
6
*/


//ListNode* removeElements(ListNode* head, int val) {
//	//base cases
//	if (head == NULL)
//		return NULL;
//
//	if (head->val == val)
//		return removeElements(head->next, val);
//
//	if (head->next == NULL && head->val != val)
//		return head;
//
//	// recursive cases
//	if (head->next->val == val)
//	{
//		ListNode* tmp = head->next;
//		head->next = tmp->next;
//		delete tmp;
//		removeElements(head->next, val);
//		return head;
//	}
//	else
//	{
//		removeElements(head->next, val);
//		return head;
//	}
//
//}

ListNode* removeElements(ListNode* head, int val) {
	//base cases
	if (head == NULL)
		return NULL;
	
	if (head->next == NULL && head->val != val)
		return head;

	// recursive case
	if (head->val == val)
		return removeElements(head->next, val);
	else
	{
		head->next = removeElements(head->next, val);
		return head;
	}

}