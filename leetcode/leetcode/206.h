#pragma once
#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Reverse a singly linked list.
*/

/*
[]
[1,2,3,4,5]
*/

// Iterative
ListNode* reverseListIt(ListNode* head) {
	if (head == NULL)
		return NULL;

	if (head->next == NULL)
		return head;

	ListNode* prev = NULL;
	ListNode* curr = head;
	ListNode* next = head->next;

	while (curr != NULL)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		if (next != NULL)
			next = next->next;
	}

	return prev;
}

// Recursive
void reverseListHelper(ListNode* prev, ListNode* curr, ListNode** newHead) {
	// end of list
	if (curr->next == NULL)
	{
		*newHead = curr;
		curr->next = prev;
		return;
	}

	reverseListHelper(curr, curr->next, newHead);
	curr->next = prev;

	//return curr;
}


ListNode* reverseListRec(ListNode* head) {
	if (head == NULL)
		return NULL;

	if (head->next == NULL)
		return head;

	ListNode* newHead = NULL;
	reverseListHelper(NULL , head, &newHead);
	
	return newHead;
}
