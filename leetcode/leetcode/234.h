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
*/


// isDone is set to true once both iterators are at the middle
bool isPalindromeHelper(ListNode** leftIt, ListNode* rightIt, bool* isDone) {
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

	bool rec = isPalindromeHelper(leftIt, rightIt->next, isDone);

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

bool isPalindrome(ListNode* head) {
	if (head == NULL)
		return true;
	
	if (head->next == NULL)
		return true;

	ListNode* leftIt = head;
	bool isDone = false;

	return isPalindromeHelper(&leftIt, head->next, &isDone);
}