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
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.
*/

/*
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	// get count of listA and listB
	int listAlength = 0;
	int listBlength = 0;
	ListNode* headAtemp = headA;
	ListNode* headBtemp = headB;

	while (headA != NULL)
	{
		headA = headA->next;
		listAlength++;
	}
	while (headB != NULL)
	{
		headB = headB->next;
		listBlength++;
	}

	// place both temp pointers equal distance from the end
	while (listAlength > listBlength)
	{
		headAtemp = headAtemp->next;
		listAlength--;
	}
	while (listBlength > listAlength)
	{
		headBtemp = headBtemp->next;
		listBlength--;
	}

	// find the intersection or reach the end of the lists
	while (headAtemp != NULL && headBtemp != NULL)
	{
		if (headAtemp == headBtemp)
			return headAtemp;
		else
		{
			headAtemp = headAtemp->next;
			headBtemp = headBtemp->next;
		}
	}

	return NULL;
}