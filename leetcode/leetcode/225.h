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
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

/*

*/

queue<int> queue1; //where pop/top will be located, where elements get pushed
queue<int> queue2; //holding stack for pop/top operations

// Push element x onto stack.
void push(int x) {
	// move everything to queue 2;
	while (queue1.size() > 0)
	{
		queue2.push(queue1.front());
		queue1.pop();
	}

	queue2.push(x);

	// move everthing back to queue 1

	while (queue2.size() > 0)
	{
		queue1.push(queue2.front());
		queue2.pop();
	}
}

// Removes the element on top of the stack.
void pop() {
	// move to queue 2
	while (queue1.size() > 1)
	{
		queue2.push(queue1.front());
		queue1.pop();
	}

	queue1.pop();

	//move back to queue 1
	while (queue2.size() > 0)
	{
		queue1.push(queue2.front());
		queue2.pop();
	}
}

// Get the top element.
int top() {
	// move to queue 2
	while (queue1.size() > 1)
	{
		queue2.push(queue1.front());
		queue1.pop();
	}

	int ret = queue1.front();
	
	queue2.push(queue1.front());
	queue1.pop();

	//move back to queue 1
	while (queue2.size() > 0)
	{
		queue1.push(queue2.front());
		queue2.pop();
	}

	return ret;
}

// Return whether the stack is empty.
bool empty() {
	return (queue1.size() == 0 && queue2.size() == 0);
}