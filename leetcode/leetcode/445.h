#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include "Solution.h"

using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/


/*
[7,2,4,3]
[5,6,4]
[]
[]
[1]
[1,2,3]
[5,6,4]
[7,2,4,3]
[2]
[2]
[1,2,3]
[]
[]
[1,2,3]
*/

int getTopVal(stack<int>& s)
{
	if (!s.empty())
	{
		int n = s.top();
		s.pop();
		return n;
	}
	else
		return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	stack<int> l1Digits;
	stack<int> l2Digits;

	// get l1 digits
	ListNode* curr = l1;
	while (curr != NULL)
	{
		l1Digits.push(curr->val);
		curr = curr->next;
	}

	// get l2 digits
	curr = l2;
	while (curr != NULL)
	{
		l2Digits.push(curr->val);
		curr = curr->next;
	}

	// construct new list using stacks
	ListNode* res = NULL;
	int carry = 0;
	while (!l1Digits.empty() || !l2Digits.empty())
	{
		int x = getTopVal(l1Digits);
		int y = getTopVal(l2Digits);

		ListNode* newNode = new ListNode(x + y + carry);
		if (!res)
		{
			res = newNode;
		}
		else
		{
			newNode->next = res;
			res = newNode;
		}

		// calculate carry
		carry = newNode->val / 10;
		newNode->val = newNode->val % 10;
	}

	if (carry > 0)
	{
		ListNode* newNode = new ListNode(carry);
		newNode->next = res;
		res = newNode;
	}

	return res;
}







int addTwoNumbers445Helper(ListNode** res, ListNode* l1, ListNode* l2)
{
	if (!l1->next && !l2->next)
	{
		int carry = 0;
		(*res) = new ListNode(l1->val + l2->val);
		if ((*res)->val >= 10)
		{
			(*res)->val -= 10;
			carry++;
		}
		return carry;
	}

	int c = addTwoNumbers445Helper(res, l1->next, l2->next);

	ListNode* n = new ListNode(l1->val + l2->val + c);
	if (n->val >= 10)
	{
		n->val -= 10;
		c = 1;
	}
	else
		c = 0;
	n->next = (*res);
	(*res) = n;

	return c;
}

ListNode* addTwoNumbers445(ListNode* l1, ListNode* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	// find shorter list
	ListNode* shorterListHead = NULL;
	ListNode* longerListHead = NULL;
	int longerLength;
	int shorterLength;
	int l1length = 0;
	int l2length = 0;

	ListNode* counter = l1;
	while (counter != NULL)
	{
		l1length++;
		counter = counter->next;
	}

	counter = l2;
	while (counter != NULL)
	{
		l2length++;
		counter = counter->next;
	}

	shorterListHead = (l1length < l2length) ? l1 : l2;
	longerListHead = (l1length < l2length) ? l2 : l1;
	longerLength = (l1length > l2length) ? l1length : l2length;
	shorterLength = (l1length > l2length) ? l2length : l1length;
	// append shorter list with zeros

	while (shorterLength < longerLength)
	{
		ListNode* z = new ListNode(0);
		//z->val = 0;
		z->next = shorterListHead;
		shorterListHead = z;
		shorterLength++;
	}

	// recurse to form result
	ListNode* res = NULL;
	int c = addTwoNumbers445Helper(&res, longerListHead, shorterListHead);
	// get last carry
	if (c > 0)
	{
		ListNode * n = new ListNode(1);
		//res->val -= 10;
		n->next = res;
		res = n;
	}
	

	// delete extra appended nodes
	ListNode* curr = shorterListHead;
	ListNode* next = shorterListHead->next;
	while (curr->val == 0 && curr != NULL)
	{
		delete curr;
		curr = next;
		if (curr->next)
			next = curr->next;
	}

	return res;
}