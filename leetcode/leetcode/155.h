#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "Solution.h"
#include <cstdint>
#include <cctype>

using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

/*
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
*/


class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> realStack;
	stack<int> minStack;
	MinStack() {
		return;
	}

	void push(int x) {
		realStack.push(x);
		if (minStack.empty() ||  x <= minStack.top())
			minStack.push(x);

		return;
	}

	void pop() {
		if (realStack.empty())
			return;

		if (!minStack.empty() && realStack.top() == minStack.top())
			minStack.pop();

		realStack.pop();

		return;
	}

	int top() {
		return realStack.top();
	}

	int getMin() {
		return minStack.top();
	}
};