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
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/*
[2,4,3]
[5,6,4]
[2,4,3]
[5, 6]
[2, 4]
[5, 6, 4]
[2]
[]
[5]
[5]
[5,5]
[5,5]
*/

// cleaner solution

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (!l1) return l2;
	if (!l2) return l1;

	ListNode* it1 = l1;
	ListNode* it2 = l2;

	ListNode* res = NULL;
	ListNode* resTail = NULL;

	int carry = 0;

	while (it1 != NULL || it2 != NULL)
	{
		int sumOne = 0;
		int sumTwo = 0;

		if (it1) sumOne = it1->val;
		if (it2) sumTwo = it2->val;

		// make new node
		ListNode* newNode = new ListNode(sumOne + sumTwo + carry);

		if (!res)
		{
			res = newNode;
			resTail = newNode;
		}
		else
		{
			resTail->next = newNode;
			resTail = resTail->next;
		}

		carry = newNode->val / 10;
		newNode->val = newNode->val % 10;

		if (it1)
			it1 = it1->next;
		if (it2)
			it2 = it2->next;
	}

	// add a new last node if necessary
	if (carry > 0)
	{
		ListNode* newNode = new ListNode(carry);
		resTail->next = newNode;
	}

	return res;
}

ListNode* addTwoNumbersOld(ListNode* l1, ListNode* l2) {
	if (!l1) return l2;
	if (!l2) return l1;

	ListNode* it1 = l1;
	ListNode* it2 = l2;

	ListNode* res = NULL;
	ListNode* resTail = NULL;
	int carry = 0;

	while (it1 != NULL || it2 != NULL)
	{
		// create the new node
		ListNode* newNode = new ListNode(0);
		if (it1 != NULL && it2 == NULL)
		{
			newNode->val = it1->val + carry;
		}
		else if (it1 == NULL && it2 != NULL)
		{
			newNode->val = it2->val + carry;
		}
		else
		{
			newNode->val = it1->val + it2->val + carry;
		}

		// have the list point to our new node
		if (!res)
		{
			res = newNode;
			resTail = res;
		}
		else
		{
			resTail->next = newNode;
			resTail = resTail->next;
		}
			
		// calculate the carry
		if (newNode->val > 9)
		{
			carry = newNode->val / 10;
			newNode->val = newNode->val % 10;
		}
		else
			carry = 0;

		//increment pointers
		if (it1)
			it1 = it1->next;
		if (it2)
			it2 = it2->next;
	}

	if (carry > 0)
	{
		ListNode* newNode;
		newNode->val = carry;
		resTail->next = newNode;
		resTail = resTail->next;
	}

	return res;
}