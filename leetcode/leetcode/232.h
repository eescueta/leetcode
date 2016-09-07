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
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

/*
[]
1
[5, 4, 8, 11, null, 13, 4, 7, 2, null, 1]
22
[5, 4, 8, 11, null, 13, 4, 7, 2, null, 1, null, null, null, null, -1]
21
[5, 4, 8, 11, null, 13, 4, 7, 2, null, 1, null, null, null, null, 4]
21
[1,2]
1
*/

// one of these must be empty AT ALL TIMES
stack<int> reverseQueue;
stack<int> popStack;

// Push element x to the back of queue.
void push(int x) {
	while (popStack.size() > 0)
	{
		reverseQueue.push(popStack.top());
		popStack.pop();
	}

	reverseQueue.push(x);
}

// Removes the element from in front of queue.
void pop(void) {
	while (reverseQueue.size() > 0)
	{
		popStack.push(reverseQueue.top());
		reverseQueue.pop();
	}

	popStack.pop();
}

// Get the front element.
int peek(void) {
	//if (popStack.size() > 0)
	//{
	//	return popStack.top();
	//}
	//else
	//{
	//	while (reverseQueue.)
	//}
	while (reverseQueue.size() > 0)
	{
		popStack.push(reverseQueue.top());
		reverseQueue.pop();
	}

	return popStack.top();
}

// Return whether the queue is empty.
bool empty(void) {
	return (reverseQueue.size() == 0 && popStack.size() == 0);
}