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
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/*
[1,2,3,2,1]
[1,2,2,1]
[1]
[1,2,3,4,5]
[]
[1,2]
[1,2,3,4]
[1,2,1,3]
*/

bool isPalindromeHelp(ListNode*& left, ListNode* right, bool& isDone) {
	// we've reached the end of the list, start comparing
	if (right->next == NULL)
	{
		if (left->val == right->val)
		{
			left = left->next;
			return true;
		}
		else
		{	
			isDone = true;
			return false;
		}
	}

	// usual case
	bool r = isPalindromeHelp(left, right->next, isDone);

	if (isDone) // right pointer has "crossed" left pointer, no more work needs to be done
	{
		return r;
	}
	else if (left->next == right) // pointers meet in list with even number of elements
	{
		isDone = true;
		return left->val == right->val;
	}
	else if (left == right) // pointers meet in list with odd num of elements
	{	
		isDone = true;
		return true;
	}
	else // check pointers have equal value
	{
		if (left->val != right->val)
		{
			isDone = true;
			return false;
		}
		else
		{
			left = left->next;
			return true;
		}

	}

	return true; // not reached
}


bool isPalindrome(ListNode* head) {
	if (!head || !head->next) return true;

	ListNode* left = head;
	bool isDone = false;

	return isPalindromeHelp(left, head->next, isDone);
}

// use a stack
bool isPalindromeStack(ListNode* head) {
	stack<int> values;

	ListNode* curr = head;
	while (curr != NULL)
	{
		values.push(curr->val);
		curr = curr->next;
	}

	curr = head;
	while (curr != NULL)
	{
		if (curr->val != values.top()) return false;

		values.pop();
		curr = curr->next;
	}

	return true;
}


// create a reverse
bool isPalindromeReverse(ListNode* head) {
	ListNode* curr = head;
	ListNode* reverseHead = NULL;

	while (curr != NULL)
	{
		if (!reverseHead)
		{
			reverseHead = new ListNode(curr->val);
		}
		else
		{
			ListNode* newHead = new ListNode(curr->val);
			newHead->next = reverseHead;
			reverseHead = newHead;
		}
		curr = curr->next;
	}

	// validate both lists are equal
	curr = head;
	ListNode* revCurr = reverseHead;

	while (curr != NULL)
	{
		if (curr->val != revCurr->val)
			return false;

		curr = curr->next;
		revCurr = revCurr->next;
	}

	return true;
}


// isDone is set to true once both iterators are at the middle
bool isPalindromeHelperOld(ListNode** leftIt, ListNode* rightIt, bool* isDone) {
	// rightIt is at the end of lsit
	if (rightIt->next == NULL)
	{
		if (rightIt->val != (*leftIt)->val )
			return false;
		else
		{
			*leftIt = (*leftIt)->next;
			return true;
		}
	}

	bool rec = isPalindromeHelperOld(leftIt, rightIt->next, isDone);

	if (rec)
	{
		if (*isDone)
			return rec;

		//	end reached
		if (*leftIt == rightIt)
		{
			*isDone = true;
			return true;
		}
		if ((*leftIt)->next == rightIt && (*leftIt)->val == rightIt->val)
		{
			*isDone = true;
			return true;
		}
		else if ((*leftIt)->next == rightIt && (*leftIt)->val != rightIt->val)
		{
			*isDone = true;
			return false;
		}

		if ((*leftIt)->val == rightIt->val)
		{
			*leftIt = (*leftIt)->next;
			return true;
		}
		else
			return false;
	}
	else
	{
		return false;
	}
}

bool isPalindromeOld(ListNode* head) {
	if (head == NULL)
		return true;
	
	if (head->next == NULL)
		return true;

	ListNode* leftIt = head;
	bool isDone = false;

	return isPalindromeHelperOld(&leftIt, head->next, &isDone);
}