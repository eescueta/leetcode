#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <list>
#include "Solution.h"

using namespace std;

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/


struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

map<RandomListNode*, RandomListNode*> nodeArchive;
RandomListNode *copyRandomList(RandomListNode *head) {
	
	//static map<int, RandomListNode*> nodeArchive;

	if (head == NULL)
		return NULL;
	

	// copy node
	RandomListNode* n;
	n->label = head->label;
	nodeArchive[head] = n;

	// copy rest of list
	n->next = copyRandomList(head->next);

	// assign random
	if (head->random == NULL)
		n->random = NULL;
	else
		n->random = nodeArchive[head->random];

	return n;
}