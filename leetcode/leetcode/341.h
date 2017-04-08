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
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

Show Company Tags
Hide Tags
*/

/*
[[1,1],2,[1,1]]
[1,[4,[6]]]
[[]]
*/


/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation

*/

class NestedInteger {
	public:
		     // Return true if this NestedInteger holds a single integer, rather than a nested list.
			     bool isInteger() const;
		
			    // Return the single integer that this NestedInteger holds, if it holds a single integer
			     // The result is undefined if this NestedInteger holds a nested list
			     int getInteger() const;
		
			     // Return the nested list that this NestedInteger holds, if it holds a nested list
			     // The result is undefined if this NestedInteger holds a single integer
			    const vector<NestedInteger> &getList() const;
		
};


class NestedIterator {
public:


	stack<NestedInteger> intStack;

	NestedIterator(vector<NestedInteger> &nestedList) {
		for (int i = nestedList.size()-1; i >= 0; i--)
		{
			intStack.push(nestedList[i]);
		}
	}

	int next() {
		NestedInteger retVal = intStack.top();
		intStack.pop();
		return retVal.getInteger();
	}

	bool hasNext() {

		while (intStack.size() > 0)
		{
			if (intStack.top().isInteger())
				return true;

			vector<NestedInteger> nextLevel = intStack.top().getList();
			intStack.pop();

			for (int i = nextLevel.size() - 1; i >= 0; i--)
			{
				intStack.push(nextLevel[i]);
			}
		}

		return false;
	}
};